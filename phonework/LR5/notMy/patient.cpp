/// \file patient.cpp
/// \brief Реализация структуры Patient
#include "patient.h"

Patient::Patient(QString policy_, QString name_, QString section_, QString doctor_)
    : policy(policy_), name(name_), section(section_), doctor(doctor_) {
}

Patient::Patient()
    : policy(""), name(""), section(""), doctor("") {
}

bool Patient::load(QTextStream& stream) {
    QString line = stream.readLine();
    QStringList splited = line.split(';');
    if (splited.size() != 5)
        return false;
    policy = splited[0];
    name = splited[1];
    section = splited[2];
    doctor = splited[3];
    return true;
}

void Patient::save(QTextStream& stream) {
    stream << policy << ';' << name << ';' <<
              section << ';' << doctor << ";\n";
}
