class Animal:
    def speak(self):
        print("Animal sound")

class Dog(Animal):
    def speak(self):
        print("Bark")

class Cat(Animal):
  pass

def make_animal_speak(animal):
    animal.speak()

dog = Dog()
cat = Cat()
make_animal_speak(dog)  # 输出: Bark
make_animal_speak(cat)  # 输出: Meow
