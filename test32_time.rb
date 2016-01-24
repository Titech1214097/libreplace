# coding: utf-8
require 'benchmark'

result = Benchmark.realtime do
  num = 0
  while num < 1000000 do
    str = "abいうえaいうえo"
    str = str.gsub(/a˘¤Śo/, 'aiueo')
    num = num + 1
  end
end
puts "#{result}s"
