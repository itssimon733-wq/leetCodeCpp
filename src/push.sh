#!/bin/bash

COMMIT_MSG="${1:-Updated C++ leetCode problem}"

echo "==========================================="
echo "🚀 Building and pushing leetCode problem..."
echo "==========================================="


# Stage and commit
echo "📦 Staging changes..."
git add -A

echo "📝 Creating commit..."

if ! git commit -m "$COMMIT_MSG"; then
    echo "⚠️ Commit failed or nothing to commit."
    exit 1
fi

# Push to GitHub and GitLab
echo "🌐 Pushing to GitHub and GitLab..."

if git push origin main; then
    echo "🎉 Successfully pushed!"
else
    echo "⚠️ Push failed. Check your remote configuration."
    exit 1
fi
