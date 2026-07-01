# Q10. What is a .gitignore file?

A `.gitignore` file tells Git which files and folders should not be tracked or committed to the repository. It helps avoid uploading compiled files, temporary files, operating system files, and IDE configuration folders.

## Arduino .gitignore

```gitignore
# Arduino compiled files
*.hex
*.elf

# Build folder
build/

# VS Code
.vscode/

# macOS
.DS_Store

# Windows
Thumbs.db
```

## Benefits
- Prevents unnecessary files from being uploaded.
- Keeps the repository clean.
- Protects temporary and generated files from version control.
