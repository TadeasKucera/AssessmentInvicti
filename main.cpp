#include <cpr/cpr.h>

#include <cstdlib>
#include <iostream>
#include <fstream>

int main() {
    cpr::Session session;
    session.SetUrl(cpr::Url{ "http://testphp.vulnweb.com/userinfo.php" });
    session.SetPayload({ {"uname", "test"}, {"pass", "test"} });

    // Post HTML request
    const auto r = session.Post();

    // Print to the console
    std::cout << "Status Code: " << r.status_code << std::endl;
    std::cout << "Response text: " << r.text.substr(100) << std::endl;

    // Write the HTML to a file
    const std::string filename{ "response.html" };
    std::ofstream file{ filename };
    file << r.text;
    file.close();

    // Open with default browser
#ifdef _WIN32
    system(("start " + filename).c_str());
#elif __APPLE__
    system(("open " + filename).c_str());
#elif __linux__
    system(("xdg-open " + filename).c_str());
#endif

    return 0;
}