# Q9. Difference Between Git Pull, Git Fetch, and Git Clone

## Git Clone

- Used to download an entire remote repository for the first time.
- Creates a complete local copy of the repository, including all files and commit history.

**Example:**

```bash
git clone https://github.com/username/repository.git
```

---

## Git Fetch

- Downloads the latest changes from the remote repository.
- Does not merge the changes into the current branch.
- Useful when you want to review updates before applying them.

**Example:**

```bash
git fetch
```

---

## Git Pull

- Downloads the latest changes from the remote repository.
- Automatically merges the downloaded changes into the current branch.
- Commonly used to keep the local repository up to date.

**Example:**

```bash
git pull
```

---

## Difference

| Command | Purpose |
|---------|---------|
| git clone | Creates a local copy of a remote repository. |
| git fetch | Downloads updates without merging them. |
| git pull | Downloads updates and merges them automatically. |

## When to Use

- Use **git clone** when working with a repository for the first time.
- Use **git fetch** to review updates before merging.
- Use **git pull** to update the local repository with the latest changes.
