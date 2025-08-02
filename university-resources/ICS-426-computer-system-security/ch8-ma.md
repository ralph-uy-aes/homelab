# Chapter 8: Access Control - Module A: Access Control Principles

#### Access Control Models
- Discretionary Access Control (DAC)
    - Owner of each controlled object decides who can access it and what permissions they have
    - DAC is used by Windows and most common Unix-like operating system
- Mandatory Access Control (MAC)
    - Administrators assign security classifications to each user and each resource
    - A user can only access a given resource if their labels are compatible
    - MAC is challenging to implement correctly, but allows very high security
    - Developed for military use but common in other high-security environments
- Role-based Access Control (RBAC)
    - Similar to MAC because administrators define permissions, but instead of clearance levels, users are assigned to one or more roles
    - Each role has a list of permissions
    - RBAC is popular in commercial applications and military systems
- Rule-based Access Control (RAC)
    - Access is determined by a set of rules configured by administrators
    - Can either be static or dynamic and may be triggered by other events
    - RAC is used to describe multiple, mutually exclusive approaches
- Attribute-based Access Control (ABAC)
    - Applies security attributes to resources, users, and environments, then defines policies governing combinations of those attributes
    - When a user requests access to a resource, it's approved or denied based on the policy
    - ABAC is a flexible system that can be used to replicate other models, or to calculate the risks of a specific action

#### Discretionary Access Control
- Provides overall security while being relatively flexible and easy to implement
- Owner sets access permissions by editing an access control list (ACL) attached to the object

#### Unix Permissions
- Read (r) - read a file or list the contents of a directory
- Write (w) - Modify a file, or create, modify, or delete files within a directory
- Execute (x) - Execute a file, or enter a directory and access its subdirectories
- Issue relates to one of the main weaknesses of DAC: it can be easy for trojan horse attacks to bypass permissions

#### NTFS Permissions
- NTFS volumes in Windows use a similar DAC model to Linux, but a bit more flexible and complex
- Security Identifier (SID) identifies a principal, like a user or group, can be displayed as a numerical string or a friendly name
- Access Control Entry (ACE) is a metadata attached to an object, represents permissions for a single SID; can contain both allow and deny rules, includes more granular permissions than Linux
- Dynamic Access Control List (DACL) is the full list of ACEs that apply to an object, includes explicit ACEs set on the object, inherited ACEs received from its parents and generic ACEs from its class

#### Mandatory Access Control
- Centrally managed by administrators
- Users aren't inherently able to unilaterally change permissions to files they've created
- Allows for much more robust security and protects against the damage done by trojan horses
- Main disadvantage of MAC is that it's much less flexible and needs much more hands-on setup and management by administrators to remain useable
- MAC systems apply security labels both to users and to resources, and the access rules depend on how the labels match up
- Lattice-based access control (LBAC) because you can construct a mathematical lattice that compares the user's clearance level to the resource's security level
    - Users have r/w access to resources of their own level
    - Users cannot read resources of a higher level, but may be able to write to them (no read-up)
    - Users can read resources of a lower level, but cannot write to them (no write-down)

#### Role-based Access Control
- Can be classified as a form of MAC since administrators centrally control access
- Works by defining roles, each with a set of rights
- Very similar to DAC groups, users can belong to one or more roles, gaining permissions of all of them
- Typically only positive, not negative permissions
- Flexible and can perform most of the functions of either DAC or MAC systems, can be changed easily by administrators by editing roles or assignment

#### Rule-based Access Control
- Uses a list of rules configured in an ACL
- Simple to implement and is widely used
- Rules can be static or dynamic and change with events
- An example is time-of-day restrictions, only allowing access at certain times

#### Attribute-based Access Control
- Next-generation because of its flexibility
- System evaluates attributes based on a set of policies which are Boolean evaluations
- Can be as complex and fine-grained as you need it to be
- One popular ABAC implementation is eXtensible Access Control Markup Language (XACML), an XML-based standard that defines a policy language, attribute elements, and system architecture to evaluate and enforce policies

#### Risk-based Access Control
- Allows administrators to define policies that determine whether a user can access a resource and require different authentication conditions based on the accessing circumstance
- Can be based on ABAC, but usually used to described the management system rather than the underlying model
- Microsoft Azure Active Directory
    1. The user signs in with single-factor authentication, such as with a password
    2. Azure Active Directory collects multiple signals based on the user's current context, signals can include user and group, device security posture, specific device, IP location, application to access, and real-time risk measurements such as user behavioral analysis
    3. When the user wants to perform an action, Azure chooses on of the following based on access policies
        - Block Access
        - Allow Access
        - Require MFA before Access
        - Require other access conditions such as password changes or device authentication

#### Time and Location-based Access Control
- Geolocation - Technique of using an IP address to determine physical location via routing information and internet registries, easy but a proxy service can bypass it
- Geofencing - The use of GPS RFID, cellular, or Wi-Fi data to identify the location of a mobile device and compare it to a virtual fence around a defined area. Service with access to the device's location service can use its location to make access control decisions
- Geotagging - An application feature that allows location data to be embedded in a photo, message, online post, etc. Most visibly used for social media apps and mobile technologies. Geotagging can be used in access control systems, but can also leak sensitive information useful to attackers

#### Failure Modes
- Systems fail
- Isn't tied to specific access control models: It's a basic principle you must consider whenever you develop a program, set access control rules, or secure assets
- A lock  for a bank vault should stay closed when it loses power, this is called fail-secure design
- A door lock leading into a secure area, but is on a fire exist route should unlock when it loses power, this is called a fail-safe design
- Fail-closed blocks all access in the event of failure
- Fail-open allows continued operation under insecure conditions 

Acr
- DAC - Discretionary Access Control
- MAC - Mandatory Access Control
- RBAC - Role-based Access Control
- RAC - Rule-based Access Control
- ABAC - Attribute-based Access Control
- ACL - Access Control List
- SID - Security Identifier
- ACE - Access Control Entry
- DACL - Dynamic Access Control List
- LBAC - Lattice-based access control
- XACML - eXtensible Access Control Markup Language