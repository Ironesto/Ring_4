#include <iostream>

class Contact {

    private:
        std::string _name;
        std::string _lstname;
        std::string _nick;
        std::string _number;
        std::string _secret;

    public:
        Contact();
        ~Contact();

        std::string getName() const;
        void        setName(std::string name);

};
