class Perm

	def self.start
		collection = [[1,9,1,1],[4,5,6,7],[7,8,9,1]]
		path(collection)
	end

	def self.path(collection)
		lowest = 1000

		for i in 0..collection[0].length - 1
			weight = combined(collection,collection[0][i],1)
			lowest = weight if weight < lowest
		end

		p "result is : #{lowest}"
		return lowest
	end

	def self.combined(collection,value,level)
		p "level start #{level}"
		lowest = 10000

		for i in 0..collection[level].length - 1
			sum = value + collection[level][i]
			lowest = sum if sum < lowest
		end
		if level < collection.length - 1
			p "level call #{level}"
			lowest = combined(collection,lowest,level+1)
		end
		
		return lowest
	end

end
Perm.start