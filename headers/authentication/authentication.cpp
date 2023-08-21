#include "authentication.hpp"

std::vector<std::string> authentication::convertSentenceToVector(const std::string& sentence) {
    std::vector<std::string> sentences;
    std::istringstream iss(sentence);
    std::string sentenceToken;

    while (std::getline(iss, sentenceToken, ',')) {
        sentences.push_back(sentenceToken);
    }

    return sentences;
}

authentication::authentication() {
    std::ifstream obj;
    obj.open("../../csv/login.csv");

    std::string line;
    while (std::getline(obj, line)) {
        std::vector<std::string> words_of_line = convertSentenceToVector(line);
        if (words_of_line.size() >= 4) {
            loadData loadData_obj(words_of_line[0], words_of_line[1], words_of_line[2], words_of_line[3]);
            head.push_back(loadData_obj);
        }
    }
    obj.close();
}

void authentication::print() {
    for (std::list<loadData>::const_iterator itr = head.begin(); itr != head.end(); ++itr) {
        const loadData& data = *itr;
        std::cout << "UserID: " << data.userid << std::endl;
        std::cout << "Password: " << data.password << std::endl;
        std::cout << "Type: " << data.type << std::endl;
        std::cout << "Active Status: " << data.active_status << std::endl;
        std::cout << "-----------------------------" << std::endl;
    }
}

bool authentication::logIn(std::string userid, std::string password, std::string type) {
    for (std::list<loadData>::iterator itr = head.begin(); itr != head.end(); ++itr) {
        if (itr->userid == userid && itr->password == password && itr->type == type) {
            itr->active_status = "1";
            return true;
        }
    }
    return false;
}

bool authentication::logOut(std::string userid, std::string password, std::string type) {
    for (std::list<loadData>::iterator itr = head.begin(); itr != head.end(); ++itr) {
        if (itr->userid == userid && itr->password == password && itr->type == type) {
            itr->active_status = "0";
            return true;
        }
    }
    return false;
}

authentication::~authentication() {
    std::ofstream newlogin("../csv/newlogin.csv");
    for (const auto& data : head) {
        newlogin << data.userid << "," << data.password << "," << data.type << "," << data.active_status << std::endl;
    }
    newlogin.close();
    std::remove("../../csv/login.csv");
    std::rename("../../csv/newlogin.csv", "../csv/login.csv");
}
