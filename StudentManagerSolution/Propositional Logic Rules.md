
## Propositional Logic Rules

---
### The turnstile
The symbol "⊢" is called the "turnstile" symbol in logic, and it is often read as "proves" or "entails". It is used to indicate that a certain conclusion can be derived from a given premise or set of premises. In other words, if you have a statement \( A \) and another statement \( B \), and you can logically derive \( B \) from \( A \), you would write this as $( A \vdash B )$.

For example, in the context of Modus Ponens:

- $( A, A \rightarrow B \vdash B )$

This reads as: "If \( A \) is true, and \( A \rightarrow B \) is true, then \( B \) is true."

---
---

### 1. Modus Ponens (MP)

**Modus Ponens (MP)**: $( A, A \rightarrow B \vdash B )$
- **Explain like I'm 10**: If you know "If it's raining, then the ground will be wet," and you see that it's raining, then you know the ground must be wet!

- **Formal Definition**: If A and (A -> B) are true, then B is true.

- **Usable Example**: If "It is raining" and "If it is raining, then the ground is wet" are true, then "The ground is wet" is also true.

- **Truth Table**:
  ```
  A | A -> B | B
  T |   T    | T
  T |   F    | F
  F |   T    | -
  F |   F    | -
  ```
  In this table, '-' means it doesn't matter what B is.

**Modus Ponens (MP)**: $( A, A \rightarrow B \vdash B )$

---

### 2. Modus Tollens (MT)

- **Explain like I'm 10**: If you know that "If you eat all your vegetables, you get dessert," and you see someone didn't get dessert, then they didn't eat all their vegetables.

- **Formal Definition**: If not B and (A -> B) are true, then not A is true.

- **Usable Example**: If "You don't get dessert" and "If you eat all your vegetables, you get dessert" are true, then "You didn't eat all your vegetables" is true.

- **Truth Table**:
  ```
  not B | A -> B | not A
    T   |   T    |   T
    T   |   F    |   -
    F   |   T    |   -
    F   |   F    |   -
  ```
**Modus Tollens (MT)**: $( \lnot B, A \rightarrow B \vdash \lnot A )$

---

### 3. Conjunction Introduction (Conj Intro)

- **Explain like I'm 10**: If you have a red ball and a blue ball, then you definitely have both a red ball and a blue ball.

- **Formal Definition**: If A and B are true, then (A and B) is true.

- **Usable Example**: If "I have a red ball" and "I have a blue ball" are true, then "I have a red ball and a blue ball" is true.

- **Truth Table**:
  ```
  A | B | A and B
  T | T |    T
  T | F |    F
  F | T |    F
  F | F |    F
  ```

**Conjunction Introduction (Conj Intro)**: $( A, B \vdash A \land B )$


---
### 4. Conjunction Elimination (Conj Elim)

- **Explain like I'm 10**: If you know you have a bag of red and blue balls, then you definitely have a red ball and a blue ball.

- **Formal Definition**: If (A and B) is true, then A and B are both true.

- **Usable Example**: If "I have a red ball and a blue ball" is true, then "I have a red ball" and "I have a blue ball" are both true.

- **Truth Table**:
  ```
  A and B | A | B
    T     | T | T
    F     | - | -
  ```
**Conjunction Elimination (Conj Elim)**: $( A \land B \vdash A, B )$

---

### 5. Disjunction Introduction (Disj Intro)

- **Explain like I'm 10**: If you have a red ball, then you can say you either have a red ball or a blue ball, even if you don't have a blue ball.

- **Formal Definition**: If A is true, then (A or B) is true.

- **Usable Example**: If "I have a red ball" is true, then "I have a red ball or a blue ball" is true.

- **Truth Table**:
  ```
  A | A or B
  T |    T
  F |    -
  ```

**Disjunction Introduction (Disj Intro)**: $( A \vdash A \lor B )$

---

### 6. Disjunction Elimination (Disj Elim)

- **Explain like I'm 10**: If you know someone has either a red ball or a blue ball, and you find out they don't have a red ball, then they must have a blue ball.

- **Formal Definition**: If (A or B) and not A are true, then B is true.

- **Usable Example**: If "I have a red ball or a blue ball" and "I don't have a red ball" are true, then "I have a blue ball" is true.

- **Truth Table**:
  ```
  A or B | not A | B
    T    |   T   | T
    T    |   F   | -
    F    |   T   | -
    F    |   F   | -
  ```
**Disjunction Elimination (Disj Elim)**: $( A \lor B, \lnot A \vdash B )$

---

### 7. Double Negation Elimination (DNE)

- **Explain like I'm 10**: Saying "It's not not raining" is the same as saying "It's raining."

- **Formal Definition**: not not A is the same as A.

- **Usable Example**: "It's not not raining" is the same as "It's raining."

- **Truth Table**:
  ```
  not not A | A
      T     | T
      F     | F
  ```
**Double Negation Elimination (DNE)**: $( \lnot \lnot A \vdash A )$

---

### 8. Implication Elimination (Imp Elim)

- **Explain like I'm 10**: Saying "If it's raining, then the ground will be wet" is the same as saying "Either it's not raining or the ground is wet."

- **Formal Definition**: (A -> B) is the same as (not A or B).

- **Usable Example**: "If it's raining, then the ground will be wet" is the same as "Either it's not raining or the ground is wet."

- **Truth Table**:
  ```
  A -> B | not A or B
    T    |     T
    F    |     F
  ```
**Implication Elimination (Imp Elim)**: $( A \rightarrow B \vdash \lnot A \lor B )$

---

### 9. De Morgan's Laws

- **Explain like I'm 10**: Saying "I don't have a red and a blue ball" is the same as saying "I don't have a red ball or I don't have a blue ball."

- **Formal Definition**:
    - not (A and B) is the same as (not A or not B).
    - not (A or B) is the same as (not A and not B).

- **Usable Example**:
    - "I don't have a red and a blue ball" is the same as "I don't have a red ball or I don't have a blue ball."

- **Truth Table**:
  ```
  not (A and B) | not A or not B | not (A or B) | not A and not B
        T       |       T        |      T       |       T
        F       |       F        |      F       |       F
  ```

**De Morgan's Laws**:
- $( \lnot (A \land B) \vdash \lnot A \lor \lnot B )$
- $( \lnot (A \lor B) \vdash \lnot A \land \lnot B )$

---

### 10. Reductio ad Absurdum (RAA)

- **Explain like I'm 10**: If saying "Unicorns are real" leads to something silly or impossible, then you know unicorns are not real.

- **Formal Definition**: If assuming not A leads to a contradiction, then A is true.

- **Usable Example**: If assuming "Unicorns are not real" leads to something impossible, then "Unicorns are real."

**Reductio ad Absurdum (RAA)**: $( \lnot A \vdash \text{Contradiction} )$ implies $( A )$

---

### 11. Tautology

- **Explain like I'm 10**: A tautology is like saying "Either it will rain today, or it won't." It's something that's always true, no matter what.

- **Formal Definition**: A statement that is always true, like (A or not A).

- **Usable Example**: "It will rain today or it won't rain today" is always true.

- **Truth Table**:
  ```
  A | A or not A
  T |     T
  F |     T
  ```
**Tautology**: $( \vdash A \lor \lnot A )$

---
---

## First Order Logic Rules

### 1. Universal Instantiation (UI)

- **Explain like I'm 10**: If you know that "All dogs bark," and you see a dog named Fido, then you know that Fido barks.

- **Formal Definition**: From "For all x, P(x)," you can say "P(a)" for any specific "a."

- **Usable Example**: From "All dogs bark," you can say "Fido barks" for a specific dog named Fido.

**Universal Instantiation (UI)**: $( \forall x, P(x) \vdash P(a) )$

#### 2. Universal Generalization (UG)

- **Explain like I'm 10**: If you look at all the apples in a basket and see that they are red, you can say "All apples in this basket are red."

- **Formal Definition**: If P(a) is true for an arbitrary a, then "For all x, P(x)" is true.

- **Usable Example**: If "This apple is red" is true for any arbitrary apple you pick from a basket, you can say "All apples in this basket are red."

**Universal Generalization (UG)**: $( P(a) \vdash \forall x, P(x) )$

#### 3. Existential Instantiation (EI)

- **Explain like I'm 10**: If you know that "Some birds can fly," and you see a bird, you can think, "Maybe this bird can fly!"

- **Formal Definition**: From "There exists an x such that P(x)," you can say "P(a)" for some specific "a."

- **Usable Example**: From "Some birds can fly," you can say "This bird can fly" for a specific bird you are looking at.

**Existential Instantiation (EI)**: $( \exists x, P(x) \vdash P(a) )$

#### 4. Existential Generalization (EG)

- **Explain like I'm 10**: If you see a flying bird, you can say "Some birds can fly" because you have proof of at least one bird that can fly.

- **Formal Definition**: If P(a) is true for some "a," then "There exists an x such that P(x)" is true.

- **Usable Example**: If "This bird can fly" is true for a bird you are looking at, you can say "Some birds can fly."

**Existential Generalization (EG)**: $( P(a) \vdash \exists x, P(x) )$

---

## Propositional Logic Symbols


1. **Modus Ponens (MP)**: $( A, A \rightarrow B \vdash B )$
2. **Modus Tollens (MT)**: $( \lnot B, A \rightarrow B \vdash \lnot A )$
3. **Conjunction Introduction (Conj Intro)**: $( A, B \vdash A \land B )$
4. **Conjunction Elimination (Conj Elim)**: $( A \land B \vdash A, B )$
5. **Disjunction Introduction (Disj Intro)**: $( A \vdash A \lor B )$
6. **Disjunction Elimination (Disj Elim)**: $( A \lor B, \lnot A \vdash B )$
7. **Double Negation Elimination (DNE)**: $( \lnot \lnot A \vdash A )$
8. **Implication Elimination (Imp Elim)**: $( A \rightarrow B \vdash \lnot A \lor B )$
9. **De Morgan's Laws**:
    - $( \lnot (A \land B) \vdash \lnot A \lor \lnot B )$
    - $( \lnot (A \lor B) \vdash \lnot A \land \lnot B )$
10. **Reductio ad Absurdum (RAA)**: $( \lnot A \vdash \text{Contradiction} )$ implies $( A )$
11. **Tautology**: $( \vdash A \lor \lnot A )$

### First-Order Logic Rules

1. **Universal Instantiation (UI)**: $( \forall x, P(x) \vdash P(a) )$
2. **Universal Generalization (UG)**: $( P(a) \vdash \forall x, P(x) )$
3. **Existential Instantiation (EI)**: $( \exists x, P(x) \vdash P(a) )$
4. **Existential Generalization (EG)**: $( P(a) \vdash \exists x, P(x) )$



