#include <cpr/cpr.h>

#include <cstdlib>
#include <iostream>
#include <fstream>

int main() {
    cpr::Session session;
    session.SetUrl(cpr::Url{ "http://testphp.vulnweb.com/login.php" });
    session.SetPayload({ {"uname", "test"}, {"pass", "test"} });
    session.SetRedirect(cpr::Redirect{ true });

    cpr::Response r = session.Post();

    std::cout << "Status Code: " << r.status_code << std::endl;

    std::string filename = "response.html";
    std::ofstream file(filename);
    file << r.text;
    file.close();

    system(("start " + filename).c_str());

    return 0;
}