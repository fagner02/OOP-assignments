#include <iostream>
#include <sstream>
#include <vector>
#include <map>

#ifndef DOCTOR_H
#define DOCTOR_H

class IPatient;
class Patient;
class IDoctor {
public:
    virtual void addPatient(IPatient* patient) = 0;
    virtual std::string getClass() = 0;
    virtual std::string getId() = 0;
    virtual std::vector<IPatient*> getPatients() = 0;
    virtual void removePatient(std::string pacienteId) = 0;
};
class Doctor : public IDoctor {
public:
    std::string className;
    std::string sender;
    std::map<std::string, IPatient*> patients;

    Doctor() = default;

    Doctor(std::string className, std::string sender);

    void addPatient(IPatient* patient);

    void removePatient(std::string patientId);

    std::string getClass();

    std::string getId();

    std::vector<IPatient*> getPatients();

    std::string toString();
};

#endif // DOCTOR_H
#include "Patient.h"