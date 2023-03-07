#!/bin/bash

# Function to check the version format
function is_valid_version {
  # Format: vx.x.x
  if [[ $1 =~ ^v[0-9]+\.[0-9]+\.[0-9]+$ ]]; then
    return 0
  else
    return 1
  fi
}

# Ask the user to input the version
read -p "Enter the version in the format vx.x.x: " VERSION

# Check the version format
if ! is_valid_version "$VERSION"; then
  echo "Error: invalid version format"
  exit 1
fi

# Ask the user to confirm continuing execution
read -p "Update the version in CMakeLists.txt. Continue? (y/n) " -n 1 -r
echo

if [[ $REPLY =~ ^[Yy]$ ]]; then
  # Check if there are any changes in Git
  if [[ -n $(git status -s) ]]; then
    # Add changes to a new commit
    git add .
    git commit -m "release: $VERSION"
  fi

  # Create a tag with the specified version
  git tag $VERSION

  # Push the tag to the remote repository
  git push origin refs/tags/$VERSION

  # Push the main branch to the remote repository
  git push origin main
fi
