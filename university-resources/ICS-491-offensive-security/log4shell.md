# Log4Shell

#### Information
- CVE ID: CVE-2021-44228

- CWEs Associated:
    - CWE-502: CWE-502 Deserialization of Untrusted Data
        - The product deserializes untrusted data without sufficiently ensuring that the resulting data will be valid
    - CWE-400: CWE-400 Uncontrolled Resource Consumption
        - The product does not properly control the allocation and maintenance of a limited resource
    - CWE-20: CWE-20 Improper Input Validation
        - The product receives input or data, but it does not validate or incorrectly validates that the input has the properties that are required to process the data safely and correctly
    - CWE-917: Improper Neutralization of Special Elements used in an Expression Language Statement
        - The product constructs all or part of an expression language (EL) statement in a framework such as a Java Server Page (JSP) using externally-influenced input from an upstream component, but it does not neutralize or incorrectly neutralizes special elements that could modify the intended EL statement before it is executed

- Description
    - Remote code execution vulnerability of the Apache Log4j 2 Java Library
    - Allowed for attackers to execute arbitrary code on affected systems (remote code execution)

- Root Cause
    - Improper input validation of the Apache Log4j 2 Library
    - Unsafe JNDI Lookups
        - Allowed attackers to inject malicious strings to connect to external servers and remotely execute code
    - Automatic Remote Code Execution
        - Library would automatically connect to malicious servers to execute Java code

- CVSS: 10.0 Critical (Version 3.x)
  
- CAPEC
    - CAPEC-137: Parameter Injection
        - Content of request parameters are manipulated
        - If attackers can supply text strings to parameters, they can inject special characters used in the encoding scheme to add or modify parameters
        - Any encoding scheme where parameters are identified and separated by text characters is potentially vulnerable to this attack
        - Prerequisites
            - The target application must use a parameter encoding where separators and parameter identifiers are expressed in regular text
            - The target application must accept a string as user input, fail to sanitize characters that have a special meaning in the parameter encoding, and insert the user-supplied string in an encoding which is then processed
    - CAPEC-6: Argument Injection
        - Attacker changes the behavior or state of an application through injecting data or syntax through the targets use of non-validated and non-filtered arguments of exposed services or methods
        - Prerequisites:
            - Target software fails to strip all user-supplied input of any content that could cause the shell to perform unexpected actions.
            - Software must allow for unvalidated or unfiltered input to be executed on operating system shell, and, optionally, the system configuration must allow for output to be sent back to client.