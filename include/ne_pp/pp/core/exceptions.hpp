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

class EOFException : public std::exception {
    private:
        std::string message;

    public:
        EOFException(const std::string& message)
            : message(message) {}
        
        const char* what() const noexcept override {
            return message.c_str();
        }

};


class LengthMismatchException : public std::exception {
    private:
        std::string message;
    
    public:
        LengthMismatchException(const std::string& message)
            : message(message) {}
        
        const char* what() const noexcept override {
            return message.c_str();
        }
};
