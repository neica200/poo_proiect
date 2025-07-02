# Courtroom Simulator – C++ OOP Project

Welcome to **Courtroom Simulator**, a fully object-oriented C++ project designed to simulate the key dynamics of a courtroom trial. The simulation includes roles such as judges, lawyers, defendants, witnesses, and evidence. The user's decisions, guided by their chosen lawyer's strategy, influence the final outcome of the trial.

This project was built with modern C++ principles, including inheritance, polymorphism, STL containers, exceptions, design patterns, and more — making it ideal as a portfolio piece or academic showcase.

---

##  Features

- **Interactive trial simulation** with multiple roles and evidence types
- **Dynamic decision-making** affecting the course and result of each trial
- **Realistic legal strategies** via the Strategy Pattern
- **Multiple judge personalities** (e.g. Strict, Empathetic, Balanced)
- **Smart evidence management** (documents, audio, witness testimony)
- **Polymorphic behavior** of legal actors
- **Singleton pattern** for global menu handling
- **Static action scoring system** to evaluate user decisions

---

##  Object-Oriented Highlights

-  Inheritance and abstract base classes  
-  Polymorphism with virtual functions  
-  STL usage: `std::vector`, `std::map`, `std::shared_ptr`, etc.  
-  Operator overloading: `<<`, `>>`, `=`, `+=`  
-  Templates (generic evidence container)  
-  Exception handling  
-  Design Patterns:
  - Singleton (for menu system)
  - Strategy (lawyer behavior)
  - Factory (for court participants)

---

##  Example Classes

- `Person` (abstract) → `Judge`, `Lawyer`, `Witness`, `Plaintiff`, `Defendant`
- `Judge` → `EmpatheticJudge`, `StrictJudge`, `BalancedJudge`
- `Evidence` (abstract) → `AudioEvidence`, `DocumentEvidence`, `WitnessEvidence`
- `Strategy` (abstract) → `AggressiveStrategy`, `CooperativeStrategy`, etc.
- `Trial` (main engine) – Manages participants, trial flow, and outcome

