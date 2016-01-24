require 'benchmark'

begin
  File.open('str.txt') do |file|
    file.each_line do |com|
      num = 0
      result = Benchmark.realtime do
        while num < 1000000 do
          str = com
          str = str.match(/(http:\/\/)([^/]*)\/(.*)/)
          num = num + 1
        end
      end
      puts "#{result}s"
    end
  end
rescue SystemCallError => e
  puts %Q(class=[#{e.class}] message=[#{e.message}])
rescue IOError => e
  puts %Q(class=[#{e.class}] message=[#{e.message}])
end
