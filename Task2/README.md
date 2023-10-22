
GIT AND GITHUB

Git and GitHub are crucial tools in modern software development. Git is a distributed version control system that allows multiple contributors to collaborate on a project while tracking changes. At the same time, GitHub is a web-based platform that provides hosting services for Git repositories, along with a range of collaborative features. This report provides an overview of Git and GitHub, their key features, benefits, and their impact on the software development industry.
For example for a bank account there is a complete record of the all the transactions taking place like deposit, withdraw, taxation, penalty, interest on principal, etc. Similarly Git helps us to track the history all the changes that have undergone in the code for any project. When the file was added or deleted or changes made in the lines of the code, etc.

Git is a version control system which is popular, Free and Open Source, fast and Scalable.

1)	Tracing The History: If someone is working on creating a website. Initially the website might only have the Signup/ Login page with some essential pages like home, about, etc. At this stage the project was pushed into git. At some later stage some another feature, say help was created but the functioning of this page was more complicated than anticipated. Now Git can help the developer go back to the stage when the website was functional and delay working on this help page for the future instead of manually deleting every unnecessary line of code which when working on complex projects can prove risky. It records changes in a special database called a repository. Each change, known as a "commit," is timestamped and tagged with a unique identifier.

2)	Collaboration: Often on a single project a team of developers are working together. In such a scenario it is imperative to track the features and contribution of each developer separately and to avoid conflicts or overriding code of different programmers. Such conflicts are resolved when the files are merging into the main program. One of the key advantages of Git is its distributed nature. Each developer maintains a local copy of the entire project repository, allowing them to work independently and offline. Changes can be synchronized with a central repository, enabling seamless collaboration.


3)	Contributors can also fork the code from or copy a folder or branch of code from some project and make their changes to solve a issue and then send a pull request to the owner of the original code to merge this contributors changes into the main code. Git excels at managing branches. Developers can create branches to work on specific features or bug fixes without affecting the main codebase. Merging branches back into the main branch is straightforward, enabling teams to work on multiple features simultaneously.

Github is a website that allows developers to store and manage their codes using git. They can make different folders or organize different projects in form of repositories. 

SETUP 

Configuring user information used across all local repositories 

•	git config --global user.name “<github_username>” 
set a name that is identifiable for credit when review version history 

•	git config --global user.email “<valid_email>” 
set an email address that will be associated with each history marker 

•	git config --global color.ui auto 
set automatic command line coloring for Git for easy reviewing


SETUP & INIT 
Configuring user information, initializing and cloning repositories

•	git init 
initialize an existing directory as a Git repository 

•	git clone [url] 
retrieve an entire repository from a hosted location via URL


•	STAGE & SNAPSHOT 
Working with snapshots and the Git staging area 

•	git status 
show modified files in working directory, staged for your next commit 

•	git add [file] 
add a file as it looks now to your next commit (stage) 
or
git add .
to add all the files in git

•	git reset [file] 
unstage a file while retaining the changes in working directory 

•	git diff
diff of what is changed but not staged 

•	git diff --staged 
diff of what is staged but not yet commited 

•	git commit -m “[descriptive message]” 
commit your staged content as a new commit snapshot


BRANCH & MERGE
Isolating work in branches, changing context, and integrating changes 

•	git branch 
list your branches. a * will appear next to the currently active branch 

•	git branch [branch-name] 
create a new branch at the current commit 

•	git checkout 
switch to another branch and check it out into your working directory 

•	git merge [branch] 
merge the specified branch’s history into the current one 

•	git log 
show all commits in the current branch’s history


INSPECT & COMPARE 
Examining logs, diffs and object information 

•	git log 
show the commit history for the currently active branch 

•	git log branchB..branchA 
show the commits on branchA that are not on branchB 

•	git log --follow [file] 
show the commits that changed file, even across renames 

•	git diff branchB...branchA 
show the diff of what is in branchA that is not in branchB 

•	git show [SHA] 
show any object in Git in human-readable format


TRACKING PATH CHANGES 
Versioning file removes and path changes 

•	git rm [file] 
the file from project and stage the removal for commit 

•	git mv [existing-path] [new-path] 
change an existing file path and stage the move git 

•	log --stat -M 
show all commit logs with indication of any paths that moved


IGNORING PATTERNS 
Preventing unintentional staging or commiting of files 

•	git config --global core.excludesfile [file] 
system wide ignore patern for all local repositories 
•	logs/ 
*.notes 
Pattern*/ 
Save a file with desired paterns as .gitignore with either direct string matches or wildcard globs.

SHARE & UPDATE 
Retrieving updates from another repository and updating local repos 

•	git remote add [alias] [url] 
add a git URL as an alias 

•	git fetch [alias] 
fetch down all the branches from that Git remote 

•	git merge [alias]/[branch] 
merge a remote branch into your current branch to bring it up to date 

•	git push [alias] [branch] 
Transmit local branch commits to the remote repository branch 

•	git pull 
fetch and merge any commits from the tracking remote branch

REWRITE HISTORY 
Rewriting branches, updating commits and clearing history 

•	git rebase [branch] 
apply any commits of current branch ahead of specified one 

•	git reset --hard [commit] 
clear staging area, rewrite working tree from specified commit

TEMPORARY COMMITS: 
Temporarily store modified, tracked files in order to change branches 

•	git stash -
Save modified and staged changes 

•	git stash list -
list stack-order of stashed file changes 

•	git stash pop -
write working from top of stash stack 

•	git stash drop -
discard the changes from top of stash stack
