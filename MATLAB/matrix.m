function M = matrix(n)

M = rot90(triu((1:n)'*ones(1,n)));