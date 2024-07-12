#include <iostream>
#include <vector>
#include <string>

// Class to represent a single phone book record
class PhoneBookRecord {
private:
    std::string name;
    std::string phoneNumber;

public:
    // Constructor
    PhoneBookRecord(const std::string& name, const std::string& phoneNumber)
        : name(name), phoneNumber(phoneNumber) {}

    // Getters
    std::string getName() const { return name; }
    std::string getPhoneNumber() const { return phoneNumber; }

    // Setters
    void setName(const std::string& newName) { name = newName; }
    void setPhoneNumber(const std::string& newPhoneNumber) { phoneNumber = newPhoneNumber; }
};

// Abstract base class for different sources of phone book records
class PhoneBookSource {
public:
    virtual std::vector<PhoneBookRecord> getRecords() const = 0;
    virtual ~PhoneBookSource() {}
};

// Concrete class representing a phone book source from a file
class FilePhoneBookSource : public PhoneBookSource {
private:
    std::string fileName;

public:
    // Constructor
    FilePhoneBookSource(const std::string& fileName) : fileName(fileName) {}

    // Method to get phone book records from the file
    virtual std::vector<PhoneBookRecord> getRecords() const override {
        // Implement logic to read records from the file and return them
        std::vector<PhoneBookRecord> records;
        // Read from file and populate records vector
        return records;
    }
};

// Service class to manage phone book records from various sources
class PhoneBookService {
private:
    std::vector<PhoneBookSource*> sources;

public:
    // Method to add a new source of phone book records
    void addSource(PhoneBookSource* source) {
        sources.push_back(source);
    }

    // Method to get all phone book records from all sources
    std::vector<PhoneBookRecord> getAllRecords() const {
        std::vector<PhoneBookRecord> allRecords;
        for (const auto& source : sources) {
            auto records = source->getRecords();
            allRecords.insert(allRecords.end(), records.begin(), records.end());
        }
        return allRecords;
    }
};
