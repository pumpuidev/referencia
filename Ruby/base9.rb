# encoding: UTF-8


class Szulo
   def initialize(x)
      @g  = x
   end
 
   attr_reader :g
   
   def add x
      @g = @g + x
   end
   
end

class Gyerek < Szulo
   def initialize(x, y)
       super(x)
       @f = y
   end
   
   def add(x,y)
       super(x)
       @f = @f + y
   end
   
   attr_reader :f 
end   

sz = Szulo.new 5
gy = Gyerek.new(10,14)
gy.add(100,200)
puts gy.g
puts gy.f
# 110
# 214

#----------------------------------------

class MyClass

      def initialize x, y
         @value1 = x
         @value2 = y
      end
    
      def show   
         puts @value1
         puts @value2
      end

   private

      def set1 x
         @value1 = x
      end

   protected         

      def add x, y
         set1 (@value1 + x) 
         @value2 += y
      end    

   public

      def try  
         puts "Publikus művelet!" 
      end
            
end

class SubClass < MyClass

   def add_other other
       other.add(@value1, @value2)
   end

end

my = MyClass.new 10, 20
# my.add 5, 6
# base9.rb:81: protected method `add' called for #<MyClass:0xb7888d28 @value2=20, @value1=10> (NoMethodError)
sb = SubClass.new 5, 6
sb.add_other my
my.show
# 15
# 26

class MyClass2

  def initialize x, y
     @value1 = x
     @value2 = y
  end

  def show   
     puts @value1
     puts @value2
  end

  def set1 x
     @value1 = x
  end

  def add x, y
     set1 (@value1 + x) 
     @value2 += y
  end    

  def try  
     puts "Publikus művelet!" 
  end
  
  public :show, :try
  private :set1
  protected :add
  
end
