#include <iostream>
#include <map>


#ifndef PATIENT_H
#define PATIENT_H
#include "Doctor.h"
class IPatient {
public:
    virtual void addDoctor(IDoctor* doctor) = 0;
    virtual std::string getDiagnostic() = 0;
    virtual std::string getId() = 0;
    virtual std::vector<IDoctor*> getDoctors() = 0;
    virtual void removeDoctor(std::string doctorId) = 0;
};
class Patient : public IPatient {
public:
    std::string diagnostic;
    std::map<std::string, IDoctor*> doctors;
    std::string sender;

    Patient() = default;

    Patient(std::string diagnostic, std::string sender);

    void addDoctor(IDoctor* doctor);

    void removeDoctor(std::string doctorId);

    std::string getDiagnostic();

    std::string getId();

    std::vector<IDoctor*> getDoctors();

    std::string toString();
};

#endif // PATIENT_H