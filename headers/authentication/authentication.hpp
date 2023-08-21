#ifndef authentication_hpp
#define authentication_hpp

#include <iostream>
#include <list>
#include <fstream>
#include <sstream>
#include <vector>

class authentication {
private:
    class loadData {
    public:
        std::string userid, password, type, active_status;
        loadData(std::string userid, std::string password, std::string type, std::string active_status)
            : userid(userid), password(password), type(type), active_status(active_status) {}
    };

    std::vector<std::string> convertSentenceToVector(const std::string& sentence);

public:
    std::list<loadData> head;
    authentication();
    void print();
    bool logIn(std::string userid, std::string password, std::string type);
    bool logOut(std::string userid, std::string password, std::string type);
    ~authentication();
};

#endif // authentication_hpp
