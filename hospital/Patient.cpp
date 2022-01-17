#include "Patient.h"

Patient::Patient(std::string diagnostic, std::string sender) : diagnostic(diagnostic), sender(sender) {}

void Patient::addDoctor(IDoctor* doctor) {
    doctors[doctor->getClass()] = doctor;
}

void Patient::removeDoctor(std::string doctorId) {
    doctors.erase(doctorId);
}

std::string Patient::getDiagnostic() {
    return diagnostic;
}
std::string Patient::getId() {
    return sender;
}
std::vector<IDoctor*> Patient::getDoctors() {
    std::vector<IDoctor*> medicos;
    for (auto& doctor : doctors) {
        medicos.push_back(doctor.second);
    }
    return medicos;
}

std::string Patient::toString() {
    std::stringstream ss;
    ss << "Patient " << sender << " has a " << diagnostic << ".\nDoctors:\n";
    for (auto x : doctors) {
        ss << x.second->getId() << "\n";
    }
    return ss.str();
}