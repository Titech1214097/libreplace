# coding: utf-8
require 'benchmark'

result = Benchmark.realtime do
  num = 0
  while num < 1000000 do
    str = "全角スペース→　←を半角に"
    str = str.gsub(/　/, ' ')
    num = num + 1
  end
end
puts "#{result}s"
