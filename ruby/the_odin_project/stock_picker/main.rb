# this appears to be bad
# big-o of this must be so high
# something like n^2
# def stock_picker(prices)
#   profit = 0
#   days = []
#   (prices.length - 1).times do |i|
#     ((i + 1)..prices.length - 1).each do |j|
#       if (prices[j] - prices[i] > profit)
#         profit = prices[j] - prices[i] 
#         days = [i, j] 
#       end
#     end
#   end
#   days
# end

# this seems better, it goes through the array only once 
# and changes the values based on the hash
def stock_picker(prices)
  min_buy_price = prices[0]
  profit = 0
  days = {}
  prices.each_with_index do |price, day|
    if price < min_buy_price
      min_buy_price = price
    elsif price - min_buy_price > profit
      profit = price - min_buy_price
      days[:buy] = prices.index(min_buy_price)
      days[:sell] = day
    end
  end
  days.values
end

p stock_picker([17, 3, 6, 9, 15, 8, 6, 1, 10]) # [1, 4]
