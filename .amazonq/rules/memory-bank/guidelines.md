# Development Guidelines

## Code Quality Standards

### Header Guards
- **Pattern**: Use `#pragma once` for all header files
- **Frequency**: 4/4 header files
- **Example**:
```cpp
#pragma once
#include <string>
class MyClass { };
```

### Namespace Usage
- **Pattern**: `using namespace std;` at file scope
- **Frequency**: All implementation files
- **Location**: After includes, before class definitions
```cpp
#include <iostream>
#include <string>
using namespace std;
```

### Include Organization
- **Order**: System headers first, then project headers
- **Pattern**: Group related includes together
```cpp
#include <iostream>
#include <string>
#include <vector>
#include "Product.h"
#include "Address.h"
```

## Structural Conventions

### Class Member Ordering
1. Private data members first
2. Public interface last
3. Static members declared before instance members

**Example**:
```cpp
class Mishloach {
    string SenderName;           // Private data
    string RecipientName;
    static int DesignPrice;      // Static member
public:
    Mishloach();                 // Public interface
    void AddProduct(Product);
};
```

### Constructor Patterns

#### Default Constructors
- Initialize all members with safe defaults
- Use empty strings for string members
- Use 0 for numeric types
- Use first enum value for enum types
```cpp
Product::Product() {
    productName = " ";
    price = 0;
    amount = 0;
    KashrutType = badats;
}
```

#### Parameterized Constructors
- Use member initializer lists for efficiency
- Initialize members in declaration order
```cpp
Product::Product(string pname, double p, int a, Kashrut k) 
    : productName(pname), price(p), amount(a), KashrutType(k) {
}
```

#### Inheritance Constructors
- Call base class constructor in initializer list
- Initialize derived members after base initialization
```cpp
Gift::Gift(string name, double price, GiftSize size, string sender, string recipient, Address address)
    : Mishloach(sender, recipient, address), giftName(name), giftPrice(price), giftSize(size) {
}
```

### Member Initialization
- **Pattern**: Use `this->` pointer for clarity in constructors when not using initializer lists
- **Frequency**: Consistent in Mishloach and Address classes
```cpp
Mishloach::Mishloach(string SenderName, string RecipientName, Address ShippingAddress) {
    this->SenderName = SenderName;
    this->RecipientName = RecipientName;
    this->ShippingAddress = ShippingAddress;
    this->ToolPrice = 15;
}
```

## Naming Conventions

### Classes and Types
- **Pattern**: PascalCase for class names
- **Examples**: `Mishloach`, `Product`, `Address`, `Gift`

### Member Variables
- **Pattern**: PascalCase for private members (SenderName, RecipientName)
- **Pattern**: camelCase for some members (productName, giftName)
- **Pattern**: snake_case for compound words (house_number)
- **Note**: Mixed conventions present - prefer consistency within each class

### Enumerations
- **Pattern**: PascalCase for enum type names
- **Pattern**: lowercase for enum values
```cpp
enum Kashrut {
    badats,
    rubin,
    lando
};

enum GiftSize {
    Small,
    Medium,
    Large
};
```

### Methods
- **Pattern**: PascalCase for public methods
- **Examples**: `AddProduct()`, `CalPrice()`, `Print()`, `IsSameKashrut()`
- **Getters**: Inline getters use camelCase with 'get' prefix
```cpp
Kashrut getKashrut() const { return KashrutType; }
```

## Method Implementation Patterns

### Const Correctness
- Mark read-only methods as `const`
- Use for getters, print methods, and calculation methods
```cpp
double CalPrice() const;
void Print() const;
Kashrut getKashrut() const { return KashrutType; }
```

### Range-Based For Loops
- **Pattern**: Use range-based loops for container iteration
- **Frequency**: 3/3 iteration contexts
```cpp
for (Product item : Vector) {
    sum += item.Sum();
}
```

### Virtual Methods
- Declare methods `virtual` when inheritance is expected
- Enables polymorphic behavior in derived classes
```cpp
virtual double CalPrice() const;
```

### Static Member Initialization
- Initialize static members outside class definition
- Place in implementation file at file scope
```cpp
// In Mishloach.cpp
int Mishloach::DesignPrice = 10;
```

## Operator Overloading

### Friend Functions
- Use friend functions for symmetric binary operators
- Implement comparison operators (>, ==)
```cpp
friend bool operator>(Mishloach&, Mishloach&);
friend bool operator==(Mishloach&, Mishloach&);

// Implementation
bool operator>(Mishloach& m1, Mishloach& m2) {
    return m1.CalPrice() > m2.CalPrice();
}
```

## STL Container Usage

### Vector Operations
- Use `push_back()` for adding elements
- Store objects by value (not pointers)
```cpp
void Mishloach::AddProduct(Product p) {
    Vector.push_back(p);
}
```

### Container Naming
- **Pattern**: Capitalize container names (Vector)
- Descriptive names preferred for clarity

## Output and Printing

### Console Output
- Use `std::cout` with `<<` operator
- Use `std::endl` for line breaks
- Provide descriptive labels for output
```cpp
cout << "Sender Name: " << SenderName << endl;
cout << "Recipient Name: " << RecipientName << endl;
```

### Print Methods
- Implement `Print()` or `print()` methods for display
- Call nested object print methods for composition
```cpp
void Mishloach::Print() const {
    cout << "Sender Name: " << SenderName << endl;
    ShippingAddress.print();  // Delegate to composed object
    for (Product item : Vector) {
        item.Print();
    }
}
```

### Switch Statements for Enums
- Use switch for enum-to-string conversions
- Handle all enum cases explicitly
```cpp
switch (giftSize) {
case Small:
    cout << "Small";
    break;
case Medium:
    cout << "Medium";
    break;
case Large:
    cout << "Large";
    break;
}
```

## Code Organization

### File Structure
- One class per header/implementation pair
- Header file (.h) contains declarations
- Implementation file (.cpp) contains definitions
- Match filenames to class names

### Commented Code
- **Pattern**: Keep commented code for reference during development
- **Frequency**: Present in Gift.cpp (getters/setters, CalPrice override)
- Indicates work-in-progress or optional features

### Indentation
- **Pattern**: Tabs for indentation
- **Brace Style**: Opening brace on same line for functions
- Consistent within each file

## Common Idioms

### Calculation Methods
- Return computed values directly
- Use accumulator pattern for sums
```cpp
double Product::Sum() {
    return amount * price;
}

double Mishloach::CalPrice() const {
    double sum = 0;
    for (Product item : Vector) {
        sum += item.Sum();
    }
    sum += ToolPrice;
    sum += DesignPrice;
    return sum;
}
```

### Validation Methods
- Return boolean for validation checks
- Use early return for failure cases
```cpp
bool Mishloach::IsSameKashrut(Kashrut k) {
    for (Product item : Vector) {
        if (item.getKashrut() != k)
            return false;
    }
    return true;
}
```

### Object Composition
- Pass objects by value for small types
- Store composed objects as members
- Use delegation for nested operations
```cpp
class Mishloach {
    Address ShippingAddress;      // Composition
    vector<Product> Vector;       // Container of composed objects
};
```

## Best Practices Observed

1. **Encapsulation**: All data members are private
2. **Const Correctness**: Read-only methods marked const
3. **Initializer Lists**: Used for efficient member initialization
4. **Static Members**: Shared data (DesignPrice) properly declared static
5. **Inheritance**: Gift properly extends Mishloach with base constructor call
6. **Type Safety**: Enums used instead of magic numbers
7. **STL Usage**: Leverages std::vector for dynamic collections
8. **Separation of Concerns**: Each class has single, clear responsibility
