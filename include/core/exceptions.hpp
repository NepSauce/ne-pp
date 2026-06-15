#include <exception>
#include <string>

class FileNotFoundException : public std::exception {
    private:
        std::string message;

    public:
        FileNotFoundException(const std::string& message)
            : message(message) {}
        
        const char* what() const noexcept override {
            return message.c_str();
        }

};