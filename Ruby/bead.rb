

begin
    f = open(ARGV[0], "r")
rescue TypeError
    puts "Adj meg egy file-t!"
rescue Errno::ENOENT
    puts "Nincs ilyen file!"   
else
    cikkek = []
    licitek = {}
    
    f.each_line{|line|
        tmp = line.strip()
        if tmp =~ /(\d+\.)\s(.*?);.*?;\s(\d+)/ 
            cikkek.concat([[$~[2], ($~[3]).to_i]])
        elsif tmp =~ /(.*):\s(\d+)\.\s(\d+)/
            licitek[$~[2].to_i] = [$~[1], $~[3].to_i]
        end     
        
    }

                   
    f2 = open("eredmeny.txt", 'w')
    i = 1
    for cikk in cikkek
        if licitek.has_key?(i)
            if licitek[i][1] >= cikk[1] 
                f2.write(i.to_s + ". " + cikk[0] + ", "+ licitek[i][0] +" " + licitek[i][1].to_s + "\n")
            end
        end          
        i = i+1
    end
    
    f.close()    
    f2.close()
end    
    
