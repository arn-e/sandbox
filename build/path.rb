require 'json'

class MinWeight
  def self.clean(json_string = '{"yo":"[[4,6,5,3],[6,7,15,2],[1,5,2,4],[3,5,2,4],[2,5,6,4]]"}')
    JSON.parse(json_string).values.first.gsub(/\]\]/,"").gsub(/\[\[/,"").split("],[").inject([]) {|new_a, i| new_a << i.split(",").map {|j| j.to_i }}.inject(0) {|sum, i| sum += i.min}
  end
end

MinWeight.clean
