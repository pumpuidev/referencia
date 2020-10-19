require 'pathname'
file = ARGV[0]
unless ARGV[0]
  puts "Adjon meg egy fájlt!"
  exit 1
end
if !File.exist?("#{file}")
  puts "Nincs ilyen file!"
  exit 1
end

line = " "
File.open(file, "r") do |f|
    File.open("eredmeny.txt", "w") do |g|
        for x in f
            egy = []
            inp = []
            egy.push(x.split(":")[1].split(",")[0])
            inp.push(x.split(":")[2])
            for z in inp
                for u in 0...z.split(" ").length
                   t=0
                   g.write("#{x.split(",")[0]}(#{z.split(" ")[u]}) =")
                   for r in egy
                        hatvany = r.split(" ").length-1
                        for h in 0...r.split(" ").length-1
                            t+=(r.split(" ")[h].to_i)*(z.split(" ")[u].to_i)**hatvany
                            hatvany-=1
                        end
                        t=t+r.split(" ")[r.split(" ").length-1].to_i
                   end
                g.write("#{t.to_i} \n")
                end           
            end
        end
    end
end