#include<bits/stdc++.h>

using namespace std;
// Declarație clasă

class Policy {
protected:
    bool isChecked{};
public:
    virtual void check(const string &str) = 0;

    bool getCheck() const {
        return isChecked;
    }

};
// Declarație clasă

class LengthPolicy : public Policy {
private:
    uint16_t minLength, maxLength;
public:
    LengthPolicy(uint16_t minLength) : minLength(minLength) {
        maxLength = 255;
    }

    LengthPolicy(uint16_t minLength, uint16_t maxLength) : minLength(minLength) {
        this->maxLength = maxLength;
    }

    void check(const string &str) override {
        if (str.size() <= maxLength && str.size() >= minLength)
            isChecked = true;
        else
            isChecked = false;
    }
};
// Declarație clasă


class ClassPolicy : public Policy {
private:
    uint16_t minClassCount;
public:

    ClassPolicy(uint16_t minClassCount) : minClassCount(minClassCount) {}

    void check(const string &str) override {
        int nr_caractere = 0;
        for (int i = 0; i < str.size(); i++)
            if (str[i] < 58 && str[i] > 47) {
                nr_caractere++;
                break;
            }
        for (int i = 0; i < str.size(); i++)
            if (str[i] < 91 && str[i] > 64) {
                nr_caractere++;
                break;
            }
        for (int i = 0; i < str.size(); i++)
            if (str[i] < 123 && str[i] > 93) {
                nr_caractere++;
                break;
            }
        for (int i = 0; i < str.size(); i++)
            if (!((str[i] < 123 && str[i] > 93) || (str[i] < 91 && str[i] > 64) || (str[i] < 58 && str[i] > 47))) {
                nr_caractere++;
                break;
            }

        if (nr_caractere >= minClassCount)
            isChecked = true;
        else
            isChecked = false;
    }
};
// Declarație clasă


class IncludePolicy : public Policy {
private:
    char characterType;
public:
    IncludePolicy(char characterType) : characterType(characterType) {}

    void check(const string &str) override {
        isChecked = false;
        if (characterType < 58 && characterType > 47)
            for (int i = 0; i < str.size(); i++)
                if (str[i] < 58 && str[i] > 47)
                    isChecked = true;
        if (characterType < 91 && characterType > 64)
            for (int i = 0; i < str.size(); i++)
                if (str[i] < 91 && str[i] > 64)
                    isChecked = true;
        if (characterType < 123 && characterType > 93)
            for (int i = 0; i < str.size(); i++)
                if (str[i] < 123 && str[i] > 93)
                    isChecked = true;
        if (!((characterType < 123 && characterType > 93) || (characterType < 91 && characterType > 64) ||
              (characterType < 58 && characterType > 47)))
            for (int i = 0; i < str.size(); i++)
                if (!((str[i] < 123 && str[i] > 93) || (str[i] < 91 && str[i] > 64) || (str[i] < 58 && str[i] > 47)))
                    isChecked = true;
    }
};
// Declarație clasă

class NotIncludePolicy : public Policy {
private:
    char characterType;
public:
    NotIncludePolicy(char characterType) : characterType(characterType) {}

    void check(const string &str) override {
        isChecked = true;
        if (characterType < 58 && characterType > 47)
            for (int i = 0; i < str.size(); i++)
                if (str[i] < 58 && str[i] > 47)
                    isChecked = false;
        if (characterType < 91 && characterType > 64)
            for (int i = 0; i < str.size(); i++)
                if (str[i] < 91 && str[i] > 64)
                    isChecked = false;
        if (characterType < 123 && characterType > 93)
            for (int i = 0; i < str.size(); i++)
                if (str[i] < 123 && str[i] > 93)
                    isChecked = false;
        if (!((characterType < 123 && characterType > 93) || (characterType < 91 && characterType > 64) ||
              (characterType < 58 && characterType > 47)))
            for (int i = 0; i < str.size(); i++)
                if (!((str[i] < 123 && str[i] > 93) || (str[i] < 91 && str[i] > 64) || (str[i] < 58 && str[i] > 47)))
                    isChecked = false;
    }
};
// Declarație clasă

class RepetitionPolicy : public Policy {
private:
    uint16_t maxCount;
public:
    RepetitionPolicy(uint16_t maxCount) : maxCount(maxCount) {}

    void check(const string &str) override {
        isChecked = true;
        int freq[127];
        for (int i = 0; i < 127; i++)
            freq[i] = 0;
        for (int i = 0; i < str.size(); i++) {
            freq[str[i]]++;
        }
        for (int j = 0; j < 127; j++) {
            if (freq[j] > maxCount)
                isChecked = false;
        }
    }
};
// Declarație clasă

class ConsecutivePolicy : public Policy {
private:
    uint16_t maxCount;
public:
    ConsecutivePolicy(uint16_t maxCount) : maxCount(maxCount) {}

    void check(const string &str) override {
        isChecked = true;
        int nr_consecutive = 1;
        for (int i = 0; i < str.size(); i++)
            if (str[i]+1 == str[i+1]) {
                nr_consecutive++;
                if (nr_consecutive > maxCount) {
                    isChecked = false;
                    break;
                }
            }
            else
                nr_consecutive = 1;

    }
};

string checkPassword(string password, vector<Policy *> d) {
    for (int i = 0; i < d.size(); i++) {
        d[i]->check(password);
        if (d[i]->getCheck() == false)
            return "NOK";
    }
    return "OK";
}
// Punct de intrare în aplicație

int main() {
    vector<Policy *> vector;
    std::vector<string> password;
    int n;
    uint16_t val1, val2, valx;
    string comand, pass;
    char c1;
    cin >> n;
    const int k = n;
    for (int i = 0; i < k; i++) {
        cin >> comand;
        if (comand == "length") {
            if (scanf("%u""%u""%u", &valx, &val2) == 2)
                vector.push_back(new LengthPolicy(valx, val2));
            else
                vector.push_back(new LengthPolicy(valx));
        } else if (comand == "class") {
            cin >> val1;
            vector.push_back(new ClassPolicy(val1));
        } else if (comand == "include") {
            cin >> c1;
            vector.push_back(new IncludePolicy(c1));
        } else if (comand == "ninclude") {
            cin >> c1;
            vector.push_back(new NotIncludePolicy(c1));
        } else if (comand == "repetition") {
            cin >> val1;
            vector.push_back(new RepetitionPolicy(val1));
        } else if (comand == "consecutive") {
            cin >> val1;
            vector.push_back(new ConsecutivePolicy(val1));
        }
    }
    while (cin >> pass) {
        password.push_back(pass);
    }
    for (int i = 0; i < password.size(); i++) {
        cout << checkPassword(password[i], vector) << endl;

    }
    return 0;
}
