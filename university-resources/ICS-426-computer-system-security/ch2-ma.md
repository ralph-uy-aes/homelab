# Chapter 2: Risk Management - Module A: Risk Management Programs

#### Risk Management Life Cycle
- Risk management is an ongoing process that continues for as long as the system, service, or organization is alive
- Four step cycle:
    1. Identify: Determine scope of assets you want to protect and list threats that can harm them
    2. Assess: Study the risk each threat poses to your assets and prioritize what should be addressed first
    3. Control: valuate and choose appropriate security controls based on the assessment results
    4. Review: Monitor control performance and use them as feedback for the next cycle iteration

#### Risk Identification
- Find potential risks to organization objectives
- First step is to determine the scope of what you're protecting
- Don't worry about the details of a threat in this phase, that comes in assessment

#### Identify assets
- When assessing risk, you first need to identify all of the organization's assets and their value
- Focus on making sure that the list of assets is complete
    - Otherwise you risk not securing everything, opening vulnerabilities
- Assets can be:
    - Information and data
    - Tangible property
    - Cash or other financial assets
    - Branding and business PR

#### Threat Assessments
- Consider all the bad things that could happen to each asset
- Include wild probabilities
- Potential threats include:
    - Accidents and disasters
    - Equipment failure
    - Supply chain failure
    - Human error and negligence
    - Malicious outsiders
    - Malicious insiders

#### Choosing Risk Identification Methods
- Perform initial research: Review internal and external sources of risk information
- Conduct interviews with knowledgeable parties: Consult key stakeholders or hire external consultants
- Bring your risk management team together: Perform open brainstorming sessions about potential risks
- Perform SWOT analysis: Examine Strengths, Weaknesses, Opportunities, Threats
- Perform scenario analysis: Imagine potential scenarios that could occur and identify risks that might arise in such a scenario
- Develop a checklist of common risks for organizations and projects similar to your own, review how many apply in your specific case
- Create a Risk Breakdown Structure (RBS): Organizes detailed risk events into broader categories, making it easier to study and organize

#### Risk Registers
- Master document of risks you've discovered and data you've correlated or calculated about them
- Should have a variety of fields such as:
    - Unique ID
    - Clear description of risk
    - Category to help group similar risks
    - Likelihood of risk occurring
    - Business impact if risk materializes
    - Overall risk level, used to define priority
    - Ways to identify risk including KRIs
    - Mitigation steps and strategies
    - Residual risk after mitigation
    - Contingencies that can be taken if prevention isn't successful
    - Owner of risk, who's responsible for managing it?

#### Risk Assessment
- One-Time
    - Risk assessment is conducted only once
    - Often as a response to planned event
    - Identify and address risks related to specific event
    - Simple and straightforward
    - New risks arise and exiting ones evolve, these assessments get outdated quickly
- Ad hoc
    - Risk assessment is carried out as needed
    - Often as a response to an immediate event
    - Performed reactively, less advance planning
    - Quickly identifies and addresses emerging risks
    - Does not follow a strict schedule, but shouldn't be simple or careless
- Recurring
    - Risk assessment is repeated regularly, often on schedule
    - Should be determined by factors like how quickly risk profile changes
    - Allow organizations to consistently monitor and adapt to evolving threats and changes in the business or technological environment
- Continuous
    - Risk assessment never ends
    - Risk identification becomes integrated in regular system monitoring
    - Most proactive and dynamic approach, potentially the most effective method
    - Resource-intensive, not cost-effective for most organizations

#### Impact Analysis
- Need to calculate both direct and indirect impact
- FISMA defines FIPS 199, requires assessment of each information system
    - According to confidentiality, integrity, availability
    - Rating each a category as low, moderate, or high impact
    - Finally, summarize them with a single aggregate score
- Security category format:
    - `SC information type = {(confidentiality, impact), (integrity, impact), (availability, impact)}`
- Aggregate takes the highest score across impact assessments, if distinct categories have high on confidentiality, integrity, availability, the aggregate shows as high on all three

#### Privacy Impact Assessments
- First, conduct a privacy threshold analysis (PTA) to determine whether the system actually handles any PII
    - Usually a legal questionnaire or something else
- If it does, perform a privacy impact assessment (PIA)
    - In-depth assessment that analyzes privacy risks, evaluates security controls that can minimize them and ensures compliance

#### Reliability Terminology
- Mean Time To Failure (MTTF)
    - Average time for a newly installed device to fail
    - Accurate for replaced components like light bulbs
    - Not so much for components that get repaired like phones
- Mean Time To Repair (MTTR)
    - Average time it takes to repair a serviceable device
- Mean Time Between Failures (MTBF)
    - Can be used interchangeably with MTTF
    - Used to describe average uptime between failures
    - High MTTR and low MTBF usually have lots of repairs
- Mean Time Between Service Incidents (MTBSI)
    - Average time between two failures, including time for repairs
    - MTBSI = MTBF + MTTR
- Recovery Time Objective (RTO)
    - Maximum expected downtime between of a device offline via failure and upon restoration
    - Describes recovery from a disaster scenario rather than just repair time
- Recovery Point Objective (RPO)
    - Maximum acceptable amount of data loss in case of a disaster
    - Applied to systems that collect and store data

#### Likelihood vs Probability
- Likelihood
    - Qualitative measurement 
    - Applicable to informal risk measurements
    - Abstract even when expressed in numbers
    - "Medium" or "3 on a 1-5 scale"
- Probability
    - Quantitative
    - Directly maps percentage to a chance of threat occurring
    - Isn't inherently more accurate than a likelihood, often based on estimates
    - "20% per year"

#### Risk Measurement
- Quantitative Risk Assessment
    - Assigns an objective value to each risk based on probability and impact cost of associated threat
    - Can give clear cost-benefit analysis for security controls
    - Must determine a concrete cost for each potential impact
- Qualitative Risk Assessment
    - Begins with probability and impact cost of each threat
    - Uses human judgement to calculate and assign priority to each risk
    - Inexact, subject to biases
    - Can work for assets and impacts with intangible costs

#### Quantitative Risk Assessment
- Asset Value (AV): Value of a specific asset, not cost
- Exposure Factor (EF): Percentage of an asset's value that would be lost if a threat occurred
- Single Loss Expectancy (SLE): Cost of a single loss from a realized threat, expressed as `SLE = AV * EF`
- Annual Rate of Occurrence (ARO): How many times can a type of loss occur per year
- Annual Loss Expectancy (ALE): Cost per year you can expect from a threat, expressed as `ALE = SLE * ARO`

#### Qualitative Risk Assessment
- Quick and easy, applicable to situations where you don't have reliable numerical data
- However, fundamentally based on biases, hunches, and guesses
- Often used for risk assessment matrices where you rank likelihood vs impact
- Probability
    - Very unlikely: Unusual possibility that should still be accounted for
    - Unlikely: Uncommon threat, not unheard of
    - Likely: Fairly common, but not extremely frequent threat
    - Very likely: Very common threat, high chance of occurring
    - Almost certain: Guaranteed to occur sooner than later
- Impact
    - Very low: Almost no damage
    - Low: Minor, but measurable damage
    - Medium: Real damage, significant recovery costs
    - High: Serious damage to overall business operations
    - Severe: Major damage or massive losses to organization
- Qualitative Analysis Tools
    - Damage Potential, Reproducibility, Exploitability, Affected Users, and Discoverability (DREAD)
        - Software threat rating system designed by microsoft
        - Factors are given a value between 1 and 3
        - Adding them together gives you an aggregate between 5 to 15
        - Higher values are more serious
    - Common Vulnerability Scoring System (CVSS)
        - Maintained by NIST for cyber vulnerabilities
        - Much more complicated than DREAD
        - Can boil the whole system down to a 1-10 scale
        - Involves scoring 14 separate metrics with non-numeric values
    - ISO 27005
        - Part of ISO's 27000 series
        - Focused on IT management at organizational level
        - Very comprehensive regarding the risks it covers
        - Generally generates a total risk metric ranging from 0 to 9

#### Risk Appetite
- How much risk your organization is prepared to pursue or accept
    - Expansionary organizations: Risk-hungry, prioritizing high-risk high-reward strategies for higher profits
    - Conservative organizations: Risk-averse, prioritizing stability and predictability even with lower profits
    - Neutral organizations: In-between the two, takes calculated risks but are careful to balance them with cautious approaches that limit overall risk levels

#### Risk Management Strategies
- Risk avoidance: Avoid risky activities
- Risk transference: Transfer risk to another party that will assume responsibility, something like insurance
- Risk mitigation: Applying security controls to reduce risk
- Risk deterrence: Applying visible controls to discourage attacks or human errors
- Risk acceptance: Hoping for the best without changing anything, usually when risk is unlikely

#### Cost Calculations
- Total Cost of Ownership (TCO): Full life cycle cost of anything the organization owns or operates
- Return on Investment (ROI): Basic measure of profitability, describing the expected reward associated with an investment

#### Exceptions vs Exemptions ISO 27001
- Exceptions are unauthorized issues that haven't been acted upon, exists as noncompliance
- Exemptions are documented and accepted noncompliance issues, permits a risk acceptance strategy for an exception

#### Securing the Security Assessment
- If you don't secure a security assessment and malicious actors get ahold of it, you have essentially given them a treasure map
- Any document concerned with threats, risks, vulnerabilities, assets, etc... should be treated as sensitive information and distributed on a need to know basis
- Fewer eyes, fewer malicious actors

#### Supply Chain Analysis
- Map out your supply chains and see how they can cause risk to business operations
- How can supply chain disruption cause failures in critical operations
- Process
    1. Identify critical vendors
    2. Assess security of each critical vendor
    3. Mitigate supplier risks based on assessment results
    4. Monitor for incidents and disruptions and respond appropriately
    5. Regularly review changes to the supply chain to identify any changes to your risk profile

#### Vendors, Suppliers, and Providers
- Vendor
    - A company or individual who provides off-the-shelf or custom goods and services to end-users
    - Closest link to the customer
- Supplier
    - Company or individual who sells business-to-business (B2B) products and services to vendors
    - Less direct interaction with consumers
- Outsource service provider
    - External company that performs business processes and tasks that otherwise might be performed in-house like software development, facilities management, IT, cloud, etc...
    - Similar risks to vendors, more intimate relationships
- Managed Service Provider (MSP)
    - Further extension of outsourcing, sometimes used interchangeably
    - Offer broader solutions with expert decision-making and real-time support
    - Great for small companies

#### Assessing Vendors
- Use the following tools:
    - Business agreements
    - Auditing rights
    - Risk questionnaires
    - Internal audit assessments
    - Penetration tests
    - Vendor monitoring