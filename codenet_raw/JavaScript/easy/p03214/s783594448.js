n = gets.chomp.to_i
a = gets.split("\s").map{|i| i.to_i }
average = (a.inject(:+).to_f / n)
a.reverse!
min = 100
ans = n
a.each_with_index do |item, idx| 
  abs = (item - average).abs
  if min >= abs
    min = abs
    ans = n - idx - 1
  end
end

puts ans
