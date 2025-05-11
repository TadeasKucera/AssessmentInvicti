#include <cpr/cpr.h>

#include <cstdlib>
#include <iostream>
#include <fstream>

int main() {
    cpr::Session session;
    session.SetUrl(cpr::Url{ "http://testphp.vulnweb.com/userinfo.php" });
    session.SetPayload({ {"uname", "test"}, {"pass", "test"} });

    const auto r = session.Post();

    std::cout << "Status Code: " << r.status_code << std::endl;

    const std::string filename{ "response.html" };
    std::ofstream file{ filename };
    file << r.text;
    file.close();

    system(("start " + filename).c_str());

    return 0;
}