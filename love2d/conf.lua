function love.conf(t)
    local FStep = io.open("steplog/step.log", "r")
    local line = FStep:read("*l")

    t.window.width = 950

    t.window.height = 950
    t.window.title = line

end
