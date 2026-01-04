# TheCorridor Agent Guide

## Build and Test
- Build (preferred): `msbuild TheCorridor.sln /p:Configuration=Debug /p:Platform=Win32` (use `Release` for shipping binaries).
- Run the game after a Debug build: `TheCorridor/Debug/TheCorridor.exe`.
- There is no automated test suite; validate changes by playing through the affected puzzles and commands. Use `rg` for code search instead of recursive greps, and avoid `ls -R` / `grep -R`.

## Change Expectations
- Keep diffs minimal and match existing patterns (Command classes, MiniGame subclasses, ServiceLocator services, and data-driven dialogue via `Data/` files).
- Keep enums in `TheCorridor/Definitions.h` synchronized with `Data/item_data.xml` and `Data/room_data.xml`; append new IDs instead of reordering existing ones to avoid breaking data bindings.
- Prefer data updates over code changes when only dialogue or item metadata changes are required.
- Use `ServiceLocator::GetConsoleWriter()` for user-facing strings and maintain current formatting.

## Gameplay, Save/Load, Networking
- Gameplay is single-player and deterministic; changes must preserve existing puzzle flows, key gating, and event handling (`ItemAcquiredEvent`, `MiniGameCompleteEvent`).
- There is no save/load system—new state should initialize safely on a fresh run and not require persistence.
- The game is offline only; do not introduce networking or remote dependencies.

## Adding New Features (e.g., new puzzle keys)
- Define new items/rooms by appending to the enums in `TheCorridor/Definitions.h` and adding matching entries in `Data/item_data.xml` and/or `Data/room_data.xml` with consistent IDs.
- Wire new items into world setup and interactions via existing components (`World::InitItems`, room inventories, mini-games, and command handlers). Use existing locking/usability flags and dialogue switching (`SwitchDialogue`, `MakeUsable`, `Lock/Unlock`).
- Update event-driven logic in `World::OnNotify` or relevant commands to unlock or reveal new content in response to mini-game completion or item acquisition.
- Playtest the full flow for any new puzzle/key: build, launch the game, exercise the new content, and confirm existing doors/keys and mini-games still behave as before.
