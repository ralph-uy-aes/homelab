# Chapter 9: Enterprise Architecture - Module B: System Architecture

#### About System Architecture
- Security controls must be tailored per risk and enterprise infrastructure
- There are multiple ways to classify the architectures found in an enterprise
- Architectures divided by network structure
    - Centralized: Network with a client-server structure based around a single server, client nodes don't directly communicate and resources are maintained separately
    - Decentralized: Network with multiple independent servers, each of which can handle its own workload for one part of the network; servers might communicate and synchronize with one another, but mostly work independently
    - Distributed: Multiple independent systems working toward a goal, may be client-server, peer-to-peer, multi-tiered, or clustered
    - Serverless: Distributed model where tasks are broken up into smaller functions on virtual servers instead of complete server-based applications
- Architectures divided by physical design
    - Virtualized: VMs and other virtualized systems that are abstracted from their underlying hardware, protected from some risks of physical systems, but face whole new ones
    - Embedded: Tightly integrated computers running specialized software, usually as ROM or flash-based firmware. Face similar threats to general-purpose computers performing the same tasks, but may not have adequate security controls
    - Mobile: Portable devices such as laptops, tablets, smartphones, and wearable devices. Most are embedded network clients, but their mobile nature and wireless networking give them a unique risk profile, also makes them useful for attacks
- Architectures divided by physical location
    - On-premises: Organization maintains services in its own facility, deployment may be physical or virtual/cloud-based and the personnel may be employees or contractors, but the organization has full control. While most on-premises network connect to the internet, internal communication is fully private
    - Colocation Center: Organization rents space in a shared third-party data center. Customer keeps full control of hardware and security, colocation center provides space, utilities, networking, and physical security
    - Service Provider: Organization rents infrastructure or services from an external provider such as a pubic cloud service provider, security responsibilities are defined by the service contract, but are typically shared between the customer and provider
- Other Architectural Models
    - Database: Servers or systems that manage large sets of data, common targets for data theft
    - Service-Oriented Architecture (SOA): Distributed application architectures based on web technologies, have multi-tier designs with a small number of large, modular services and are popular for large-scale enterprise applications
    - Microservice architecture: Alternative to SOA that uses a large number of relatively independent, finely-grained services. Common for smaller, cloud-native web applications on a serverless architecture
    - Operational Technology (OT): Computers and networks that interact with their physical environment, such as sensors and controls for physical machinery. Include ICS and IoT networks

#### Infrastructure Considerations
- Availability: Percentage of time a resource is expected to be operating and responsive
- Resilience: System's ability to remain operational even under adverse conditions and to recover quickly in case of failure
- Cost: Cost-effective infrastructure and security controls allow you to increase performance and add additional layers of defense
- Responsiveness: Ability of a system to react quickly, such as changing configurations or responding to a threat
- Scalability: Ability to cope with significant changes in demand without suffering performance problems, service interruptions, or procedural bottlenecks
- Ease of deployment: Infrastructure that are difficult to deploy have more opportunities for failure
- Risk transference: Reduce IT and security workload by making someone else responsible (ie, a third party)
- Ease of recovery: The more quickly a resource can be restored to full operation after failure, the less it wil damage business operations or reputation
- Patch availability: Security patches are essential for responding to newly discovered threats; infrastructure that can't be patched will become progressively less secure over time
- Power: Power consumption is an important concern for computing infrastructure
- Compute: Computer power such as CPU, memory, and I/O resources are critical for any infrastructure

#### Centralized vs Decentralized
- Centralized
    - Pros
        - Simple and efficient
        - Common in small networks
        - Single point of control
        - Easy to monitor and maintain
        - Easy to patch and enforce security
    - Cons
        - Single point of failure
        - Any failure takes down the whole system
        - Difficult to restore from something serious
        - Single high-value target to attackers
- Decentralized
    - Pros
        - Multiple redundant control points
        - Adds availability and resilience
        - You can even plan around outages or upgrades
        - More scalable
    - Cons
        - Costly
        - Complex
        - Might fail to maintain consistent data
        - Lack of central oversight
- Distributed
    - Pros
        - More resilient
        - Highly available
        - No SPOF
        - Increase communication and resource sharing between nodes
    - Cons
        - More difficult to design and implement
        - Challenging to synchronize data or apply patches uniformly
        - Not as scalable
    - N-tier architecture is a form of distributed architecture, splitting a service into separate components

#### Virtualized Architecture
- Virtualized systems have led to massive transformations in data center architecture
- Platform virtualization separates OS from their underlying hardware
    - Efficiently use steadily increasing computing power by consolidating smaller services onto a smaller number of physical devices
- Two common approaches: Virtual Machines (VM) and containers

#### Virtual Machines
- Relatively independent virtual system that accesses system resources through a hypervisor, aka a Virtual Machine Monitor (VMM)
- The hardware is a set of virtual devices controlled by a hypervisor
- Hypervisor mediates access, so multiple VMs can't interfere with each other
- Hypervisors:
    - Type 1 or bare metal: Installed directly on the host hardware and fully control it
    - Type 2 or hosted: Run as applications in a regular host operating system, less efficient

#### Containers
- Similar to a VM, isolated from other containers on the same host and the host OS
- Unlike a VM, contains only specific applications and services rather than a complete operating system
    - Uses a container engine like Docker instead of a hypervisor
- Less flexible than VMs, but are more efficient since they can share host's kernel and core OS resources

#### Security Benefits of Virtualization and Containerization
- VMs and containers can be easily backed up or transferred, improving availability and fault tolerance.
- VMs and containers use standardized physical hosts, so scaling or replicating a deployment is easy.
- Since physical and logical nodes are decoupled, you can perform maintenance and upgrades on one level without affecting others.
- VMs and containers can replicate tasks that used to be typically performed by specialized hardware devices. For example, you can deploy a firewall or wireless network controller as a VM, or install a network monitoring application as a container. 
- Virtual desktop infrastructures (VDIs) deploy user workstations in VM form with remote access software so users can access them from any device. They allow complete control of desktop configuration and security within the data center without IT staff going out to maintain user workstations directly.
- Containers allow easy deployment of applications and application components; their lightweight nature makes them popular building blocks for microservice applications.

#### Virtual Machine Vulnerabilities
- Core problem is that compromise of the control software can potentially compromise the whole architecture
- VMs and containers are typically created from pre-configured templates and images which can already be compromised
- VM escape can attack the hypervisor from inside the VM

#### Infrastructure as Code (IaC)
- Uses machine-readable definition files to generate and deploy service components in an automated process
- Significant security implications
    - Turns network design and deployment into a software development project
    - All the risks of software development are added to network design, and insecurely developed code can bake vulnerabilities into your cloud infrastructure

#### Real-Time Operating Systems (RTOS)
- Specialized operating system designed for an instant response as data arrives
- Excellent choice for responsive devices that interact primarily with physical systems and can't afford processing delays, such as medical, industrial, or vehicle computers
- Usually have very different designs than typical embedded Linux distributions, but can have similar vulnerabilities

#### Operational Technology
- Industrial Control Systems (ICS)
    - Used for factory machinery and distribution infrastructures
    - Networked for central monitoring and control
    - Popular standards include Distributed Control System (DCS), used primarily for process control systems and Supervisory Control And Data Acquisition (SCADA), designed for monitoring and limited control of large-scale distribution systems
- Building Automation Systems (BAS)
    - Control building utility systems such as HVAC, lighting, fire suppression, and security systems
    - Networked to improve efficiency and disaster response
- Vehicle Control Systems
    - Link computer-controlled components within a vehicle
    - Use internal networks to link electronic components within a single vehicle, but external network connectivity has become common
- Internet of Things (IoT)
    - OT field with more cloud-based and web-based architecture than ICS or BAS
    - Include sensor networks, inventory management, smart appliances, and automation systems
    - Designed to integrate with IT networks and cloud services and use wireless networking technologies

#### OT Network Risks
- Many devices on OT networks are specialized embedded systems; while that can decrease their attack surface, it also means they’re usually designed with limited security services and may use insecure protocols with weak or no encryption to improve performance.
- OT devices and connections are often out in the “real world” rather than in physically secure locations, making it easier for attackers to get physical access.
- Many OT networks rely on physical airgaps and non-standard protocols to avoid traditional network attacks and malware. This is an increasingly ineffective strategy since network convergence means they increasingly have connectivity with IT systems and the internet
- OT systems, as well as general-purpose servers and workstations on industrial networks, are often not hardened and updated like their IT counterparts. In fact, the latter are often obsolete systems running long-unsupported software.
- OT networks can make security scanning and monitoring difficult. Tools meant for IT networks can be useless or even actively harmful to OT systems, so you need different vulnerability management methods.
- Organizations often disregard OT networks as part of their enterprise security strategy or forget how they interact with IT. This is dangerous whether IT or OT assets come under attack

#### Cloud Service Models
- Software-as-a-Service (SaaS)
    - Subscription-based
    - AKA on-demand software
    - Generally built as a web application installed in the provider's data center
- Platform-as-a-Service (PaaS)
    - Access to computing platform or software environment the customer can use to develop and host web-based applications
    - PaaS can be used to develop applications for the customer to offer as their own web service, or it can be used for internal applications
    - Provider manages the underlying infrastructure and development tools, so customer has to do only the software development
- Infrastructure-as-a-Service (IaaS)
    - Access to lower-level computing and network resources, such as storage devices, processing, entire computers, and even whole networks
    - Customer can install and manage OS, file systems, and whatever else needed
    - CSP manages and is responsible for the underlying hardware

#### Shared Responsibility on the Cloud
- IaaS requires the most customer management of all the cloud service models. The customer manages the applications, data, runtime, middleware, and operating systems. As a customer, you have the most responsibility for security at this level, but even there the CSP controls security for physical infrastructure and low-level networking, storage, and virtualization
- PaaS requires less customer management. The customer is responsible for the applications and data they run and store, while the CSP deploys VMs and middleware
- SaaS requires the least amount of management. The CSP controls and secures the whole stack; the customer just uses the software and keeps their credentials secure

#### Cloud Deployment Models
- Public
    - Service is available to the general public, paid or free
    - Can be owned and hosted by any public or private organization
    - Convenient and inexpensive, but may not meet all security or compliance requirements
- Private
    - Service is accessible only to a single organization
    - Might be on-premises or off and might be owned and managed by the organization itself or a third party
- Community
    - Shared between multiple organizations with common concerns and needs
    - Designed for users with shared compliance needs such as government organizations or heavily regulated industries
- Hybrid
    - Has some combination of public, private, and community cloud characteristics
    - Public CSP might offer isolated virtual private clouds for customers with strict security needs
    - Or a private cloud user can allocate public cloud resources via cloud bursting

#### Serverless Architectures
- Servers are used, but the responsibility of managing server infrastructure shifts from the customer to the CSP
- You can deploy applications without worrying about infrastructure
    - Cheaper to design and deploy
    - More scalable and granular
- But this technology is new and security is questionable

#### Cloud Security Risks
- Any cloud service is still a network service and subject to network attacks. The risk is no different from traditional network services, but it can differ from traditional desktop applications.
- Using an off-premises cloud service requires an internet connection with all its limitations. In addition to any latency or bandwidth constraints based on your connection, you must secure cloud communications.
- Integrating cloud and on-premises services adds additional risk since you’re weakening the network perimeter. You must consider how to protect the larger attack surface.
- Apart from the need for secure communications with outside providers, using a cloud service for sensitive information means giving another entity some control over it. The CSP might not pay the same attention to its security, especially if your data is subject to special regulatory requirements.
- Attacks on public cloud services can affect several or even all customers at a time, so your data might be compromised by an attack on or facilitated by another customer.
- Public clouds often contain services and appliances provided by third-party vendors. Even if you trust the CSP, that doesn’t necessarily mean the same trust or compliance extends to other vendors who sell there.
- Individual cloud services have different privacy policies on how they might share customer data and information, and precisely what jurisdictional privacy laws apply

#### Common Cloud Vulnerabilities
- Application programming interfaces(APIs)used for communication between cloud services
- Passwords, encryption keys, and API keys used to secure data and services
- Security and compliance for cloud-based data
- Insufficient logging, monitoring, or documentation of deployed resources