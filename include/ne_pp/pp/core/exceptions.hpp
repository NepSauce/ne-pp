#include <exception>
#include <string>

namespace ne_pp::pp {
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


class NullPointerException : public std::exception {
    private:
        std::string message;
    
    public:
        NullPointerException(const std::string& message)
            : message(message) {}
        
        const char* what() const noexcept override {
            return message.c_str();
        }
};

class OutOfBoundsException : public std::exception {
    private:
        std::string message;
    
    public:
        OutOfBoundsException(const std::string& message)
            : message(message) {}
        
        const char* what() const noexcept override {
            return message.c_str();
        }
};

class InvalidCSVStructureException : public std::exception {
    private:
        std::string message;
    
    public:
        InvalidCSVStructureException(const std::string& message)
            : message(message) {}
        
        const char* what() const noexcept override {
            return message.c_str();
        }
};

class EmptyStringException : public std::exception {
    private:
        std::string message;

    public:
        EmptyStringException(const std::string& message)
            : message(message) {}
};
}
