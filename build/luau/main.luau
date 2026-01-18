local p = Instance.new("Part")

print("ClassName:", p.ClassName) -- Part
print("Name:", p.Name) -- "" (puste)

p.Name = "Podłoga główna"

print("Name:", p.Name) -- "" (puste)
print(Vector3.new(0, 1, 2))
--print(p.Position.x) -- 0
--p.Position = Vector3.new(0, 5, 10)
--print(p.Position.y) -- 5

p:Destroy() -- Destroyed: Podłoga główna (Part)
