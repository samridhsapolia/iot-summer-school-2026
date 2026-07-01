# Q9. Difference between git clone, git fetch, and git pull

## git clone
- Creates a complete copy of a remote repository on your local computer.
- Downloads all files, branches, and commit history.
- Used when working on a repository for the first time.

Example:
```bash
git clone https://github.com/username/repository.git
```

## git fetch
- Downloads the latest changes from the remote repository.
- Does not merge the changes into the current branch.
- Used when you want to review updates before merging.

Example:
```bash
git fetch origin
```

## git pull
- Downloads the latest changes and automatically merges them into the current branch.
- Used to keep your local repository up to date.

Example:
```bash
git pull origin main
```

## Summary

| Command | Purpose | When to Use |
|---------|----------|-------------|
| git clone | Copy entire repository | First time downloading a repository |
| git fetch | Download changes only | Review updates before merging |
| git pull | Download and merge changes | Update your local repository |
