# Project Structure

## Directory Organization

```
MishloachManot/
├── .amazonq/rules/memory-bank/    # Amazon Q documentation
├── MishloachManot/                # Main source directory
│   ├── x64/Debug/                 # Build artifacts and object files
│   ├── *.cpp                      # Implementation files
│   ├── *.h                        # Header files
│   ├── MishloachManot.vcxproj     # Visual Studio project file
│   └── MishloachManot.vcxproj.*   # Project configuration files
├── x64/Debug/                     # Compiled executables
│   └── MishloachManot.exe         # Main executable
└── MishloachManot.sln             # Visual Studio solution file
```

## Core Components

### 1. Mishloach (Main Package Class)
**File**: Mishloach.h, Mishloach.cpp
- Central class managing gift packages
- Stores sender/recipient names and shipping address
- Maintains vector of Product objects
- Handles price calculations (products + design + tool costs)
- Provides comparison operators (>, ==)
- Validates kashrut consistency across products

### 2. Product (Item Management)
**File**: Product.h, Product.cpp
- Represents individual items in a package
- Properties: name, price, amount, kashrut type
- Calculates total cost per product (price × amount)
- Supports three kashrut certifications via enum

### 3. Address (Location Data)
**File**: Address.h, Address.cpp
- Encapsulates delivery location information
- Fields: city, street, house number
- Provides printing functionality for address display

### 4. Gift (Extended Package Type)
**File**: Gift.h, Gift.cpp
- Inherits from Mishloach class
- Adds special gift item with name, price, and size
- Supports three size categories: Small, Medium, Large
- Extends base package functionality with gift-specific features

### 5. Main Application
**File**: MishloachManot.cpp
- Entry point demonstrating system usage
- Creates sample products, addresses, and packages
- Demonstrates package creation and product addition
- Shows iteration and printing of multiple packages

## Architectural Patterns

### Object-Oriented Design
- **Encapsulation**: Private data members with public interfaces
- **Inheritance**: Gift extends Mishloach for specialized functionality
- **Polymorphism**: Virtual CalPrice() method for extensible pricing
- **Composition**: Mishloach contains Address and vector of Products

### Data Management
- **STL Containers**: Uses std::vector for dynamic product collections
- **Value Semantics**: Objects support copying and assignment
- **Static Members**: Shared DesignPrice across all Mishloach instances

### Type Safety
- **Enumerations**: Type-safe kashrut and gift size classifications
- **Const Correctness**: Const methods for read-only operations
- **Friend Functions**: Controlled access for comparison operators

## Component Relationships

```
Mishloach (core)
├── contains → Address (1:1)
├── contains → vector<Product> (1:many)
└── inherited by → Gift (specialization)

Product
└── has → Kashrut enum (type)

Gift
├── extends → Mishloach
└── has → GiftSize enum (type)
```

## Build System
- **Platform**: Windows (Visual Studio)
- **Configuration**: x64 Debug build
- **Output**: Console application (.exe)
- **Project Type**: Visual C++ native project
