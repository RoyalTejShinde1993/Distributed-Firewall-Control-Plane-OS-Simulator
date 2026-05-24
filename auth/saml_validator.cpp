#include "saml_validator.h"

bool SAMLValidator::validate(const std::string& xml) {
    return xml.find("<Assertion") != std::string::npos;
}