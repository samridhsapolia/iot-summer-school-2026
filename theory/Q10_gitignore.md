# Q10. What is a .gitignore File?

## Answer

A `.gitignore` file tells Git which files and folders should not be tracked or uploaded to the repository. It is commonly used to ignore compiled files, temporary files, operating system files, and IDE configuration folders.

## Example .gitignore for an Arduino Project

```gitignore
# Compiled output files
*.hex
*.elf

# Build folders
build/

# VS Code settings
.vscode/

# macOS
.DS_Store

# Windows
Thumbs.db
```

## Advantages

- Keeps the repository clean.
- Prevents unnecessary files from being uploaded.
- Reduces repository size.
- Avoids sharing IDE-specific configuration files.
