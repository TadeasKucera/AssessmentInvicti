#include <cpr/cpr.h>

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <string_view>

consteval const char* post_url() {
    return "http://testphp.vulnweb.com/userinfo.php";
}

// Post HTML request to login to testphp.vulnweb.com
cpr::Response post_request(std::string_view url) {
    cpr::Session session;
    session.SetUrl(cpr::Url{ std::string(url) });
    session.SetPayload({ {"uname", "test"}, {"pass", "test"} });
    return session.Post();
}

// Write the HTML to a file
void save_response_to_file(const std::string& filename, const std::string& content) {
    std::ofstream file{ filename };
    if (!file)
    {
        throw std::ios_base::failure("Failed to open file: " + filename);
    }
    file << content;
    file.close();
}

// Open file with default application
void open_in_browser(const std::string& filename) {
#ifdef _WIN32
    system(("start " + filename).c_str());
#elif __APPLE__
    system(("open " + filename).c_str());
#elif __linux__
    system(("xdg-open " + filename).c_str());
#else
    std::cerr << "Unsupported platform." << std::endl;
#endif
}

int main() {
    try {
        const auto r = post_request(post_url());
        std::cout << "Status Code: " << r.status_code << std::endl;

        const std::string filename{ "response.html" };
        save_response_to_file(filename, r.text);
        open_in_browser(filename);
    } catch (const std::exception& e) {
        std::cerr << "Exception thrown: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown exception occured." << std::endl;
        return 2;
    }
    return 0;
}