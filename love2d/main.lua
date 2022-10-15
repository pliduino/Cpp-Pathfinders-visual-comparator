FStep = io.open("steplog/step.log", "r")
FPath = assert(io.open("steplog/path.log", "r"))

Screen_size = 900


States = {}
Positions = {}
Edges = {}

N_states = 500
N_edges = 3
Step_size = (Screen_size) / N_states

Path = {}

function Sleep(n)
    local t = os.clock()
    while os.clock() - t <= n do
        -- nothing
    end
end

function LoadPath()
    local pathString = FPath:read("*l")
    Path = SplitInt(pathString)

end

function DrawPath()
    local i = 1
    while true do
        if (Path[i + 1] == nil) then
            break
        end
        love.graphics.setColor(200, 0, 255)
        local nextpos = Path[i + 1] * 1 + 1
        love.graphics.line(Positions[Path[i] + 1][1] * Step_size + 15, Positions[Path[i] + 1][2] * Step_size + 15,
            Positions[nextpos][1] * Step_size + 15,
            Positions[nextpos][2] * Step_size + 15)

        i = i + 1
    end
end

function SplitInt(str)
    result = {};

    for match in str:gmatch("%w+") do
        table.insert(result, match * 1);
    end
    return result;
end

function LoadValues()
    local fVertex = assert(io.open("steplog/vertices.log", "r"))
    local fArestas = assert(io.open("steplog/arestas.log", "r"))
    local vertices = fVertex:read("*a")
    local arestas = fArestas:read("*a")
    fVertex:close()
    fArestas:close()
    local i = 1

    for line in vertices:gmatch("([^\n]*)\n?") do
        if (line ~= "") then
            Positions[i] = SplitInt(line)
            States[i] = 0
            N_states = N_states + 1
            i = i + 1
        end
    end

    i = 1
    for line in arestas:gmatch("([^\n]*)\n?") do
        if (line ~= "") then
            Edges[i] = SplitInt(line)
            Edges[i][1] = Edges[i][1] + 1
            Edges[i][2] = Edges[i][2] + 1

        end

        i = i + 1
    end


end

function UpdateStates()
    local line = FStep:read("*l")
    if line == nil then
        return
    end

    local splitted = SplitInt(line)
    if line ~= "#" then
        States[splitted[1] + 1] = tonumber(splitted[2])
    end


    Sleep(.0)
end

function love.load()
    local line = FStep:read("*l")

    love.graphics.setBackgroundColor(255, 255, 255)
    LoadValues()
    LoadPath()
end

function love.update(dt)
    UpdateStates()
end

function love.draw()
    local activeNode
    local endFlag = false
    for i, vertex in ipairs(Positions) do
        local x = vertex[1] + 10
        local y = vertex[2] + 10
        local state = States[i]



        if state == 0 then
            love.graphics.setColor(0.5, 0.5, 0.5)
        elseif state == 1 then
            love.graphics.setColor(1, 1, 0.4)
        elseif state == 2 then
            activeNode = i
            love.graphics.setColor(0, 0.8, 0)
        elseif state == 3 then
            love.graphics.setColor(0, 0, 0)
        elseif state == 4 then
            love.graphics.setColor(1, 0, 0)
        elseif state == 5 then
            endFlag = true
            love.graphics.setColor(0, 0, 1)
        end

        love.graphics.circle("fill", x * Step_size, y * Step_size, 10)
        love.graphics.setColor(0, 0, 0)
        love.graphics.circle("line", x * Step_size, y * Step_size, 10)

        if endFlag == false then
            for index, edge in ipairs(Edges) do
                if (edge[1] == activeNode) or (edge[2] == activeNode) then
                    love.graphics.line(Positions[edge[1]][1] * Step_size + 15, Positions[edge[1]][2] * Step_size + 15,
                        Positions[edge[2]][1] * Step_size + 15,
                        Positions[edge[2]][2] * Step_size + 15)
                end

            end

        else
            DrawPath()


        end

    end

end
