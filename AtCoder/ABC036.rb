class ABC036
  class A
    def self.input
      @a, @b = STDIN.gets.chomp.split(' ').map { |num| num.to_i }
    end
    def self.solve
      self.input
      @b / @a + (@b % @a != 0 ? 1 : 0)
    end
  end

  class B
    def self.input
      @n = STDIN.gets.chomp.to_i
      @squares = []
      @n.times { @squares << STDIN.gets.chomp }
    end
    def self.solve
      self.input
      result = ''
      @n.times do |i|
        @n.times { |j| result << @squares[@n - j - 1][i] }
        result << "\n"
      end
      result
    end
  end

  class C
    def self.input
      @n = STDIN.gets.chomp.to_i
      @as = []
      @n.times { @as << STDIN.gets.chomp.to_i }
    end
    def self.solve
      self.input
      table = {}
      @as.uniq.sort.each_with_index { |a, index| table[a] = index }
      @as.map { |a| table[a] }.join("\n")
    end
  end

  class D
    def self.input
    end
    def self.solve
      self.input
    end
  end
end

puts ABC036::C.solve
