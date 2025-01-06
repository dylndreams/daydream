local core = require "core"
local command = require "core.command"
local keymap = require "core.keymap"
local console = require "plugins.console"

command.add(nil, {
  ["project:build-project"] = function()
    core.log "Building..."
    console.run {
      command = "make",
      file_pattern = "(.*):(%d+):(%d+): (.*)$",
      on_complete = function() core.log "Build complete" end,
    }
  end
})

keymap.add { ["ctrl+r"] = "project:build-project" }
