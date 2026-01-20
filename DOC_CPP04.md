# Subtype Polymorphism, Abstract Classes e Interfaces en C++

## Introducción

Este documento explica tres conceptos fundamentales de la programación orientada a objetos en C++: **Subtype Polymorphism**, **Abstract Classes** e **Interfaces**. Usaremos los ejercicios ex02 y ex03 como ejemplos prácticos.

## Private vs Protected

### Private

- Los miembros (atributos o métodos) declarados como private solo pueden ser accedidos desde dentro de la propia clase.
- Ni las clases derivadas (hijas) ni el código externo pueden acceder directamente a ellos.
- Ejemplo:
```cpp
class Foo {
private:
    int x; // Solo accesible dentro de Foo
};
```

### Protected

- Los miembros declarados como protected pueden ser accedidos desde la propia clase y también desde las clases derivadas.
- El código externo sigue sin poder acceder directamente.
- Ejemplo:
```cpp
class Bar {
protected:
    int y; // Accesible en Bar y en cualquier clase que herede de Bar
};
```

## 1. Subtype Polymorphism (Polimorfismo de Subtipos)

### ¿Qué es?

El polimorfismo de subtipos permite que un objeto de una clase derivada se comporte como un objeto de su clase base, pero manteniendo su comportamiento específico. Esto se logra mediante **funciones virtuales**.

### Ejemplo en ex02: AAnimal y sus derivadas

```cpp
// Clase base abstracta
class AAnimal {
protected:
    std::string _type;
public:
    virtual ~AAnimal();
    virtual void makeSound() const = 0;  // Función virtual pura
};

// Clases derivadas
class Dog : public AAnimal {
public:
    virtual void makeSound() const { std::cout << "Woof!" << std::endl; }
};

class Cat : public AAnimal {
public:
    virtual void makeSound() const { std::cout << "Meow!" << std::endl; }
};
```

### Polimorfismo en acción:

```cpp
// En main.cpp ex02:
AAnimal* zoo[6];
for (int k = 0; k < 6; ++k) {
    if (k < 3) zoo[k] = new Dog();  // Asignamos Dog* a AAnimal*
    else zoo[k] = new Cat();        // Asignamos Cat* a AAnimal*
}

// Polimorfismo: cada animal hace SU sonido específico
for (int k = 0; k < 6; ++k)
    zoo[k]->makeSound();  // Llama Dog::makeSound() o Cat::makeSound()
```

### ¿Cómo funciona?

1. **Binding dinámico**: En tiempo de ejecución, C++ determina qué versión de `makeSound()` llamar
2. **Tabla virtual (vtable)**: Cada clase con funciones virtuales tiene una tabla que apunta a las implementaciones correctas
3. **Puntero virtual (vptr)**: Cada objeto tiene un puntero oculto a su vtable

## 2. Abstract Classes (Clases Abstractas)

### ¿Qué es?

Una clase abstracta es una clase que **no puede ser instanciada directamente** porque contiene al menos una **función virtual pura** (= 0).

### Ejemplo: AAnimal en ex02

```cpp
class AAnimal {
    // ...
    virtual void makeSound() const = 0;  // Función virtual pura
};

// ¡ESTO NO COMPILA!
// AAnimal animal;  // Error: no se puede instanciar clase abstracta
```

### Propósito de las clases abstractas:

1. **Definir interfaz común**: Todas las clases derivadas DEBEN implementar `makeSound()`
2. **Prevenir instanciación accidental**: No puedes crear un "animal genérico"
3. **Forzar especialización**: Obligas a crear subclases concretas

### Ejemplo práctico:

```cpp
// ex02 - AAnimal es abstracta
const AAnimal* j = new Dog();  // ✅ OK: Dog implementa makeSound()
const AAnimal* i = new Cat();  // ✅ OK: Cat implementa makeSound()
AAnimal* bad = new AAnimal(); // ❌ Error de compilación
```

- Una clase con al menos un método virtual puro (`= 0`) no puede ser instanciada directamente.
- El compilador impide crear objetos de tipo `AAnimal` (por ejemplo, `AAnimal a;` da error).
- Solo puedes crear objetos de clases derivadas que implementen todos los métodos virtuales puros.

**En cambio, Animal:**

- Tiene un método virtual, pero **no es puro** (no tiene `= 0`).
- Puedes crear objetos de tipo `Animal`.

**Resumen:**  
El `= 0` en el método virtual es lo que hace que la clase sea abstracta y no se pueda instanciar.

---
No es **estrictamente necesario** que una clase abstracta tenga constructores, pero **es recomendable** y útil por varias razones:

**¿Por qué tener constructores en una clase abstracta?**
- **Inicialización de atributos:** Aunque no puedes crear objetos de la clase abstracta directamente, **las clases derivadas** sí heredan sus atributos y pueden usar sus constructores para inicializarlos.
- **Facilita la reutilización:** Permite que las clases derivadas llamen al constructor base para inicializar los atributos comunes.
- **Gestión de recursos:** Si la clase abstracta gestiona recursos (memoria, archivos, etc.), el constructor puede encargarse de inicializarlos.

**¿Se ejecutan los constructores de la clase abstracta?**
- **Sí:** Cuando creas un objeto de una clase derivada, **primero se ejecuta el constructor de la clase abstracta** (base), luego el de la derivada.

**¿Debo inicializar los atributos en la clase abstracta?**
- **Sí, es buena práctica.** Así te aseguras de que los atributos heredados estén correctamente inicializados.

**Resumen:**

- No es obligatorio, pero sí recomendable que una clase abstracta tenga constructores y que estos inicialicen los atributos.
- Los constructores de la clase abstracta se ejecutan al crear objetos de clases derivadas.


## 3. Interfaces

### ¿Qué es?

Una interfaz es un "contrato" que define qué métodos debe implementar una clase, sin proporcionar implementación. En C++, se implementan como clases abstractas puras (solo funciones virtuales puras).

### Ejemplo: ICharacter e IMateriaSource en ex03

```cpp
// Interfaz ICharacter
class ICharacter {
public:
    virtual ~ICharacter() {}
    virtual std::string const & getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};

// Interfaz IMateriaSource
class IMateriaSource {
public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};
```

### Implementación de interfaces:

```cpp
// Character implementa ICharacter
class Character : public ICharacter {
private:
    std::string _name;
    AMateria* _inv[4];
public:
    // DEBE implementar TODOS los métodos de ICharacter
    virtual std::string const & getName() const { return _name; }
    virtual void equip(AMateria* m) { /* implementación */ }
    virtual void unequip(int idx) { /* implementación */ }
    virtual void use(int idx, ICharacter& target) { /* implementación */ }
};
```

### Ventajas de las interfaces:

1. **Desacoplamiento**: El código que usa `ICharacter` no necesita saber si es `Character` u otra implementación
2. **Flexibilidad**: Puedes cambiar la implementación sin afectar el código cliente
3. **Testabilidad**: Puedes crear mocks que implementen la interfaz

## 4. Comparación Práctica

### AAnimal (Clase Abstracta) vs ICharacter (Interfaz)

| Aspecto | AAnimal (ex02) | ICharacter (ex03) |
|---------|----------------|-------------------|
| **Propósito** | Clase base con comportamiento común | Contrato puro sin implementación |
| **Miembros** | Tiene datos (`_type`) y métodos implementados | Solo métodos virtuales puros |
| **Herencia** | Proporciona funcionalidad base | Define únicamente interfaz |
| **Uso** | Representa una jerarquía de tipos | Define capacidades/comportamientos |

### Ejemplo de uso en ex03:

```cpp
// Polimorfismo a través de interfaces
IMateriaSource* src = new MateriaSource();  // MateriaSource implementa IMateriaSource
ICharacter* me = new Character("me");       // Character implementa ICharacter
ICharacter* bob = new Character("bob");

// Usamos las interfaces, no las clases concretas
AMateria* ice = src->createMateria("ice");
me->equip(ice);
me->use(0, *bob);  // Polimorfismo: usa la implementación real de Character
```

## 5. Conceptos Clave para Recordar

### Virtual Destructor
```cpp
// ¡SIEMPRE virtual en clases base!
class AAnimal {
    virtual ~AAnimal();  // Permite destrucción correcta de objetos derivados
};
```

**¿Por qué?** Sin destructor virtual:
```cpp
AAnimal* animal = new Dog();
delete animal;  // ¡Solo llama ~AAnimal()! Memory leak del Brain del Dog
```

### Clone Pattern (ex03)
```cpp
class AMateria {
    virtual AMateria* clone() const = 0;  // Patrón de clonación
};

class Ice : public AMateria {
    virtual AMateria* clone() const { return new Ice(*this); }
};
```

### Deep Copy con polimorfismo:
```cpp
// En MateriaSource::learnMateria
_known[i] = m->clone();  // Usa polimorfismo para clonar el tipo correcto
```

## 6. Errores Comunes

### 1. Olvidar virtual destructor
```cpp
class Base {
    ~Base();  // ❌ NO virtual
};
// Resultado: memory leaks en delete base_ptr
```

### 2. No implementar todos los métodos de interfaz
```cpp
class BadCharacter : public ICharacter {
    // ❌ Olvida implementar getName()
    // Error: clase sigue siendo abstracta
};
```

### 3. Slicing en paso por valor
```cpp
void func(AAnimal animal);  // ❌ Paso por valor
Dog dog;
func(dog);  // ¡Slice! Se pierde la parte Dog

void func(AAnimal& animal);  // ✅ Paso por referencia
func(dog);  // Mantiene polimorfismo
```

## 7. Buenas Prácticas

1. **Usa destructores virtuales** en clases base
2. **Prefiere referencias a punteros** cuando no necesites null
3. **Implementa Rule of Three/Five** en clases que manejan recursos
4. **Usa interfaces** para definir contratos claros
5. **Prefiere composición sobre herencia** cuando sea posible

## Conclusión

- **Subtype Polymorphism**: Permite que objetos derivados se comporten como su base manteniendo su especialización
- **Abstract Classes**: Definen interfaces parciales con algo de implementación compartida
- **Interfaces**: Definen contratos puros que las clases deben cumplir

Estos conceptos trabajan juntos para crear código flexible, mantenible y extensible. El polimorfismo es la base que permite que tanto clases abstractas como interfaces funcionen efectivamente en C++.

---
---
---
# Análisis del `ex03`

### 1. Vista General del Sistema

El proyecto implementa un **sistema de materias mágicas** con:

- **Materias** (hechizos) que pueden ser aprendidas, creadas y usadas
- **Personajes** que pueden equipar y usar materias
- **Fuentes de materias** que almacenan "recetas" y crean nuevas instancias

### 2. Jerarquía de Herencia
```
┌─────────────────┐
│   AMateria      │ ← Clase abstracta base
│   (abstract)    │
├─────────────────┤
│ #_type: string  │
│ +getType()      │
│ +clone()=0      │ ← Método virtual puro
│ +use()          │
└─────────────────┘
         △
         │ hereda
    ┌────┴─────┐
    │          │
┌───▼────┐ ┌───▼────┐
│  Ice   │ │  Cure  │ ← Clases concretas
├────────┤ ├────────┤
│+clone()│ │+clone()│
│+use()  │ │+use()  │
└────────┘ └────────┘

┌──────────────┐
│ ICharacter   │ ← Interfaz pura
│ (interface)  │
├──────────────┤
│ +getName()=0 │
│ +equip()=0   │
│ +unequip()=0 │
│ +use()=0     │
└──────────────┘
         △
         │ implementa
     ┌───▼────────┐
     │ Character  │ ← Implementación concreta
     ├────────────┤
     │ -_name     │
     │ -_inv[4]   │
     │ -_floor[16]│
     │ +getName() │
     │ +equip()   │
     │ +unequip() │
     │ +use()     │
     └────────────┘

┌───────────────────┐
│ IMateriaSource    │ ← Interfaz pura
│ (interface)       │
├───────────────────┤
│ +learnMateria()=0 │
│ +createMateria()=0│
└───────────────────┘
         △
         │ implementa
    ┌────▼───────────┐
    │MateriaSource   │ ← Implementación concreta
    ├────────────────┤
    │ -_known[4]     │
    │+learnMateria() │
    │+createMateria()│
    └────────────────┘
```
### 3. Diagrama de Dependencias Completo
```
    ┌─────────────────┐
    │   IMateriaSource│◄─────┐
    │   (interface)   │      │
    └─────────────────┘      │
             △               │
             │ implements    │ uses
    ┌────────▼────────┐      │
    │  MateriaSource  │      │
    │─────────────────│      │
    │ -_known[4]      │      │
    │                 │◄─────┤ ┌──────────┐
    │ +learnMateria() │      └─│   main   │
    │ +createMateria()│        │          │
    └─────────────────┘        └──────────┘
             │                      │
             │ stores               │ uses
             ▼                      ▼
    ┌─────────────────┐    ┌──────────────┐
    │    AMateria     │◄───│ ICharacter   │
    │   (abstract)    │    │ (interface)  │
    │─────────────────│    │──────────────│
    │ #_type          │    │ +getName()=0 │
    │ +getType()      │    │ +equip()=0   │
    │ +clone()=0      │    │ +unequip()=0 │
    │ +use(target)    │    │ +use()=0     │
    └─────────────────┘    └──────────────┘
             △                      △
        ┌────┴──────┐               │ implements
        │           │               │
  ┌─────▼────┐ ┌────▼───┐   ┌───────▼────────┐
  │   Ice    │ │  Cure  │   │   Character    │
  │──────────│ │────────│   │────────────────│
  │+clone()  │ │+clone()│   │ -_name         │
  │+use()    │ │+use()  │   │ -_inv[4]       │◄──┐
  └──────────┘ └────────┘   │ -_floor[16]    │   │
                            │ +getName()     │   │
                            │ +equip()       │   │ stores
                            │ +unequip()     │   │
                            │ +use()         │───┘
                            └────────────────┘
```

### 4. Análisis Detallado de Relaciones
**4.1 Relación: MateriaSource ←→ AMateria**
```cpp
class MateriaSource {
private:
    AMateria* _known[4];  // ALMACENA punteros a AMateria
};
```
**Tipo de relación: Agregación** (has-a)

- `MateriaSource` **almacena** hasta 4 materias aprendidas
- Usa `AMateria::clone()` para crear copias
- Usa `AMateria::getType()` para identificar tipos

**Flujo:**

1. `learnMateria(AMateria* m)` → clona y almacena
2. `createMateria(string type)` → busca por tipo y clona

**4.2 Relación: Character ←→ AMateria**
```cpp
class Character {
private:
    AMateria* _inv[4];    // INVENTARIO: materias equipadas
    AMateria* _floor[16]; // SUELO: materias desequipadas (anti-leak)
};
```
**Tipo de relación: Composición** (owns-a)

- `Character` **posee** las materias en su inventario
- Responsable de la gestión de memoria (delete en destructor)
- Usa `AMateria::use(ICharacter&)` para activar efectos

**4.3 Relación: AMateria ←→ ICharacter**
```cpp
class Character {
private:
    AMateria* _inv[4];    // INVENTARIO: materias equipadas
    AMateria* _floor[16]; // SUELO: materias desequipadas (anti-leak)
};
```
**Tipo de relación: Dependencia funcional**

- `AMateria::use()` necesita un `ICharacter` como objetivo
- Usa `ICharacter::getName()` para los mensajes

**4.4 Relación: Ice/Cure ←→ AMateria**

**Tipo de relación: Herencia** (is-a)

- `Ice` **es un** `AMateria` de tipo "ice"
- `Cure` **es un** `AMateria` de tipo "cure"
- Implementan `clone()` y `use()` de forma específica

### 5. Flujo de Datos Completo

```
1. CREACIÓN Y APRENDIZAJE
   main → new Ice() → MateriaSource::learnMateria() → Ice::clone()

2. CREACIÓN DE MATERIAS
   main → MateriaSource::createMateria("ice") → busca tipo → Ice::clone()

3. EQUIPAR MATERIAS
   main → Character::equip(materia) → almacena en _inv[slot]

4. USO DE MATERIAS
   main → Character::use(0, target) → _inv[0]->use(target) → Ice::use(target)
```

### 6. Patrones de Diseño Identificados
**6.1 Abstract Factory Pattern**
```cpp
IMateriaSource* src = new MateriaSource();
AMateria* ice = src->createMateria("ice");  // Factory method
```
**6.2 Prototype Pattern**
```cpp
AMateria* Ice::clone() const {
    return new Ice(*this);  // Clona el objeto actual
}
```
**6.3 Strategy Pattern**
```cpp
// Diferentes estrategias de uso según el tipo de materia
ice->use(target);   // "shoots an ice bolt"
cure->use(target);  // "heals wounds"
```

### 7. Gestión de Memoria
```
CREACIÓN:
main → new Ice() → MateriaSource::learnMateria() → Ice::clone() → new Ice

TRANSFERENCIA:
MateriaSource::createMateria() → Ice::clone() → new Ice → Character::equip()

DESTRUCCIÓN:
Character::~Character() → delete _inv[i] → Ice::~Ice() → AMateria::~AMateria()
```
**Puntos críticos:**
- `Character::_floor[16]` previene memory leaks en `unequip()`
- `MateriaSource` clona en lugar de transferir ownership
- Destructores virtuales aseguran cleanup correcto

### 8. Forward Declarations y Dependencias Circulares
```cpp
// En AMateria.hpp
class ICharacter; // forward declaration

// En ICharacter.hpp  
class AMateria; // forward declaration
```
**¿Por qué?**

- `AMateria::use()` necesita `ICharacter&`
- `ICharacter::equip()` necesita `AMateria*`
- Forward declarations rompen la dependencia circular

### 9. Tabla de Responsabilidades

| Clase | Responsabilidad Principal | Gestiona |
|-------|--------------------------|----------|
| AMateria | Definir interfaz común de materias | Tipo, comportamiento base |
| Ice/Cure | Implementar materias específicas | Efectos específicos |
| ICharacter | Definir interfaz de personajes | Contrato de comportamiento |
| Character | Implementar lógica de personaje | Inventario, uso de materias |
| IMateriaSource | Definir interfaz de fuente | Contrato de creación |
| MateriaSource | Implementar fábrica de materias | Catálogo, creación |

### 10. Conclusión
El sistema utiliza:

- **Interfaces** (`ICharacter`, `IMateriaSource`) para desacoplar
- **Clases abstractas** (`AMateria`) para compartir comportamiento
- **Herencia** (`Ice`, `Cure`) para especializar comportamiento
- **Agregación/Composición** para gestionar recursos
- **Polimorfismo** para permitir extensibilidad

Esta arquitectura permite añadir nuevos tipos de materias o personajes sin modificar el código existente, siguiendo **el principio abierto/cerrado**.

---

### 1. Resumen de Clases y Roles
- **AMateria**: Clase base abstracta para todas las materias (hechizos).
- **Ice, Cure**: Clases derivadas de AMateria, representan tipos concretos de materia.
- **ICharacter**: Interfaz pura para personajes.
- **Character**: Implementa ICharacter, representa un personaje con inventario de materias.
- **IMateriaSource**: Interfaz pura para fuentes de materias.
- **MateriaSource**: Implementa IMateriaSource, almacena y crea materias conocidas.

### 2. Jerarquía de Herencia
```
AMateria (abstract)
│
├── Ice
└── Cure

ICharacter (interface)
│
└── Character

IMateriaSource (interface)
│
└── MateriaSource
```
### 3. Relaciones entre Clases
- **MateriaSource** almacena punteros a `AMateria` (array `_known[4]`).
- **Character** almacena punteros a `AMateria` en su inventario (`_inv[4]`) y en el "floor" (`_floor[16]`).
- **MateriaSource** puede crear nuevas instancias de `AMateria` (usando `clone()`).
- **Character** puede equipar, usar y desequipar materias (`AMateria`).
- **Ice** y **Cure** implementan el método `clone()` para permitir copias polimórficas.
- **AMateria** define el método virtual `use(ICharacter&)`, que es implementado por las derivadas.
- **Character** llama a `use()` de las materias equipadas, pasando como argumento otro `ICharacter`.

### 4. Diagrama de Dependencias (UML simplificado)
```
+-------------------+        +-------------------+
|   IMateriaSource  |<-------|   MateriaSource   |
|-------------------|        |-------------------|
| +learnMateria()   |        | - _known[4]       |
| +createMateria()  |        | +learnMateria()   |
+-------------------+        | +createMateria()  |
                             +-------------------+
                                    |
                                    v
                             +-------------------+
                             |     AMateria      |<------------------+
                             |-------------------|                   |
                             | #_type            |                   |
                             | +clone()          |                   |
                             | +use()            |                   |
                             +-------------------+                   |
                              ^                ^                     |
                              |                |                     |
                        +-----+-----+    +-----+-----+               |
                        |   Ice     |    |   Cure    |               |
                        +-----------+    +-----------+               |
                              |                |                     |
                              +----------------+                     |
                                    |                                |
                                    v                                |
+-------------------+        +-------------------+                   |
|   ICharacter      |<-------|   Character       |-------------------+
|-------------------|        |-------------------|
| +equip()          |        | - _inv[4]         |
| +unequip()        |        | - _floor[16]      |
| +use()            |        | +equip()          |
| +getName()        |        | +unequip()        |
+-------------------+        | +use()            |
                             | +getName()        |
                             +-------------------+
```

### 5. Explicación de las Interacciones
- **MateriaSource** aprende materias (`learnMateria`) y puede crear nuevas (`createMateria`) usando el método `clone()` de `AMateria`.
- **Character** puede equipar materias (`equip`), desequiparlas (`unequip`) y usarlas (`use`). El uso de una materia llama a su método `use`, pasando como argumento otro personaje (`ICharacter&`).
- **Ice** y **Cure** son tipos concretos de `AMateria`, cada uno con su propia implementación de `clone()` y `use()`.
- **AMateria** es la base común para todas las materias, permitiendo polimorfismo.
- **ICharacter** y **IMateriaSource** son interfaces que definen el contrato que deben cumplir `Character` y `MateriaSource`.

### 6. Flujo típico en main.cpp
- Se crea una fuente de materias (`MateriaSource`) y aprende dos tipos (`Ice`, `Cure`).
- Se crea un personaje (`Character`).
- El personaje equipa materias creadas por la fuente (`createMateria`).
- El personaje usa las materias sobre otro personaje.

### 7. Resumen de Dependencias
- **MateriaSource** depende de `AMateria` (almacena y clona).
- **Character** depende de `AMateria` (equipar, usar, desequipar).
- **Ice/Cure** dependen de `AMateria` (herencia).
- **AMateria** depende de `ICharacter` (para el método `use`).
- `main.cpp` depende de todas las clases para crear y manipular objetos.

---

## diferencia entre Copy Constructor, Assignment Operator y Clone()

### Copy Constructor

**¿Qué es?**
- Es el constructor especial que crea un nuevo objeto como copia de otro existente.
- Sintaxis:
```cpp
AMateria(const AMateria& other);
```
- Se llama cuando:
    - Creas un objeto a partir de otro: `AMateria b(a)`;
    - Pasas un objeto por valor a una función.

**¿Qué hace?**
- Inicializa el nuevo objeto copiando los atributos del objeto fuente.
- Debe hacer copia profunda si hay punteros o recursos dinámicos.

### Assignment Operator

**¿Qué es?**
- Es el operador especial que copia el contenido de un objeto existente a otro objeto ya creado.
- Sintaxis:
```cpp
AMateria& operator=(const AMateria& other);
```
- Se llama cuando:
    - Asignas un objeto a otro: a = b;

**¿Qué hace?**
- Borra (libera) los recursos actuales del objeto destino (si es necesario).
- Copia los atributos del objeto fuente al destino.
- Debe manejar auto-asignación (`if (this != &other)`).

### Clone

**¿Qué es?**
- Es un método virtual que crea una copia polimórfica del objeto.
- Sintaxis:
```cpp
virtual AMateria* clone() const = 0;
```
- Se llama cuando:
    - Quieres duplicar un objeto a través de un puntero/base polimórfica.

**¿Qué hace?**
- Devuelve un puntero a un nuevo objeto, creado con el copy constructor.
- Permite copiar el tipo real del objeto, incluso si lo apuntas con un puntero a la base.

**Ejemplo:**
```cpp
AMateria* m = new Ice();
AMateria* copy = m->clone(); // copy es un nuevo Ice, aunque m es AMateria*
```

### Resumen de diferencias

| Característica      | Copy Constructor           | Assignment Operator           | Clone                       |
|---------------------|---------------------------|------------------------------|-----------------------------|
| ¿Cuándo se llama?   | Al crear un objeto nuevo  | Al asignar a objeto existente| Al pedir copia polimórfica  |
| Sintaxis            | `Class(const Class&)`     | `Class& operator=(const&)`   | `virtual Class* clone() const` |
| Retorno             | Nada (constructor)        | Referencia al objeto         | Puntero a nuevo objeto      |
| Uso polimórfico     | No                        | No                           | Sí                          |
| Crea objeto nuevo   | Sí                        | No (usa objeto existente)    | Sí                          |

**En resumen:**

**Copy constructor**: crea un objeto nuevo como copia de otro.
**Assignment operator**: copia el contenido de un objeto a otro ya existente.
**Clone**: crea una copia polimórfica, útil para duplicar objetos derivados a través de punteros a la base.

### Clone() crea una copia polimórfica porque:

- `clone()` es un método virtual en la clase base (`AMateria`), y cada clase derivada (`Ice`, `Cure`, etc.) lo implementa para devolver una copia de sí misma.
- Si tienes un puntero a la base (`AMateria*`), al llamar a `clone()`, se ejecuta la versión de la clase derivada real (por ejemplo, `Ice::clone()`), y te devuelve un nuevo objeto del tipo correcto (por ejemplo, un nuevo `Ice`).

**Ejemplo:**
```cpp
AMateria* m = new Ice();
AMateria* copy = m->clone(); // copy es un nuevo Ice, aunque m es AMateria*
```
Así, puedes duplicar el objeto **sin saber su tipo concreto**.

**Diferencia con el copy constructor:**

- El **copy constructor** (`Ice(const Ice&)`) solo se usa cuando sabes el tipo concreto y creas una copia directa:
```cpp
Ice original;
Ice copia(original); // copia directa, tipo conocido
```
- **clone()** permite copiar el objeto **a través de un puntero o referencia a la base**, manteniendo el tipo real del objeto derivado.

**Resumen:**

- **Copy constructor**: copia directa, tipo concreto conocido.
- **clone()**: copia polimórfica, tipo concreto desconocido, útil en colecciones de punteros a la base.

---
---
---
# RESOLVER

```
El subject dice:
If they try to add a Materia to
a full inventory, or use/unequip a non-existent Materia, nothing should happen (but bugs
are still forbidden). The unequip() member function must NOT delete the Materia!
Handle the Materias your character leaves on the floor as you like.
Save the addresses before calling unequip(), or anything else, but
don’t forget that you have to avoid memory leaks.

Qué pasa con la materia que estoy tratando de guardar en el _inv? No queda como un leak de memoria? No es considerada un bug?
```

Sí, tal como está, si el inventario está lleno y llamas a equip(m), el puntero m puede quedar sin dueño y convertirse en un leak si el llamador pierde la referencia. Eso es un bug según el subject: “avoid memory leaks”.

Dos arreglos puntuales:

1. Character::equip: si el inventario está lleno, guarda la Materia en el “suelo” (_floor) para conservar la propiedad y liberarla en el destructor. El inventario no cambia (“nothing should happen” externamente), pero evitas el leak.
```CPP
// ...existing code...
void Character::equip(AMateria* m) {
    if (!m)
        return ;
    for (int i = 0; i < 4; ++i)
        if (_inv[i] == 0) {
            _inv[i] = m;
            return ;
        }
    // inventario lleno: conservar propiedad dejando la materia en el "suelo"
    for (int i = 0; i < 16; ++i) {
        if (_floor[i] == 0) {
            _floor[i] = m;
            return ;
        }
    }
    // Si también está lleno el suelo, aquí podrías decidir liberar (delete m) para no fugar memoria,
    // o reportarlo de alguna forma. Lo dejamos sin borrar para respetar el espíritu de "nothing should happen".
}
// ...existing code...
```

2. MateriaSource::learnMateria: ahora mismo clonas y no borras el argumento, por lo que fugas la instancia pasada (new Ice(), new Cure() en main). O bien tomas propiedad directa (guardar m), o si prefieres clonar, borra el original tras clonar.

Opción A (tomar propiedad):
```CPP
// ...existing code...
void MateriaSource::learnMateria(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; ++i) {
    if (_known[i] == 0) {
            _known[i] = m; // toma propiedad
            return ;
        }
    }
    // lleno: no tomar propiedad para no fugar
    // delete m; // opcional si quieres garantizar cero fugas
}
// ...existing code...
```

Opción B (clonar y borrar el original):
```CPP
// ...existing code...
void MateriaSource::learnMateria(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; ++i) {
        if (_known[i] == 0) {
            _known[i] = m->clone();
            delete m;           // evita fuga del argumento
            return ;
        }
    }
    // lleno: no aprendemos esta materia; evitar fuga
    delete m;
}
// ...existing code...
```

Notas:

- Con estos cambios, evitas fugas tanto al equipar con inventario lleno como al aprender materias en la fuente.
- La semántica de propiedad queda clara: Character toma propiedad de las materias que recibe (equipadas o al suelo). MateriaSource o toma propiedad directa del puntero o clona y borra el original, pero nunca lo deja huérfano.
