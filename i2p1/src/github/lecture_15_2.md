## Forking

### Forking a repository

You might fork a project to propose changes to the upstream, or original, repository. In this case, it's good practice to regularly sync your fork with the upstream repository. To do this, you'll need to use Git on the command line. You can practice setting the upstream repository using the same [octocat/Spoon-Knife](https://github.com/octocat/Spoon-Knife) repository you just forked.

1. On GitHub.com, navigate to the [octocat/Spoon-Knife](https://github.com/octocat/Spoon-Knife) repository.
2. In the top-right corner of the page, click **Fork**.
![Fork button](./images/help/repository/fork_button.jpg)

### Cloning your forked repository

Right now, you have a fork of the Spoon-Knife repository, but you don't have the files in that repository locally on your computer.

1. On GitHub.com, navigate to **your fork** of the Spoon-Knife repository.
2. Above the list of files, click ![The download icon](icons/download-24.svg) **Code**.
  !["Code" button](./images/help/repository/code-button.png)
3. To clone the repository using HTTPS, under "Clone with HTTPS", click ![The clipboard icon](icons/paste-24.svg). To clone the repository using an SSH key, including a certificate issued by your organization's SSH certificate authority, click **Use SSH**, then click ![The clipboard icon](icons/paste-24.svg). To clone a repository using GitHub CLI, click **Use GitHub CLI**, then click ![The clipboard icon](icons/paste-24.svg).
  ![The clipboard icon for copying the URL to clone a repository](./images/help/repository/https-url-clone.png)
4. Open Terminal.
5. Change the current working directory to the location where you want the cloned directory.
6. Type `git clone`, and then paste the URL you copied earlier. It will look like this, with your GitHub username instead of `YOUR-USERNAME`:
  ```shell
  $ git clone https://github.com/YOUR-USERNAME/Spoon-Knife
  ```

7. Press **Enter**. Your local clone will be created.
  ```shell
  $ git clone https://github.com/YOUR-USERNAME/Spoon-Knife
  > Cloning into `Spoon-Knife`...
  > remote: Counting objects: 10, done.
  > remote: Compressing objects: 100% (8/8), done.
  > remove: Total 10 (delta 1), reused 10 (delta 1)
  > Unpacking objects: 100% (10/10), done.
  ```

### Configuring Git to sync your fork with the original repository

When you fork a project in order to propose changes to the original repository, you can configure Git to pull changes from the original, or upstream, repository into the local clone of your fork.

1. On GitHub.com, navigate to the [octocat/Spoon-Knife](https://github.com/octocat/Spoon-Knife) repository.
2. Above the list of files, click ![The download icon](icons/download-24.svg) **Code**.
  !["Code" button](./images/help/repository/code-button.png)
3. To clone the repository using HTTPS, under "Clone with HTTPS", click ![The clipboard icon](icons/paste-24.svg). To clone the repository using an SSH key, including a certificate issued by your organization's SSH certificate authority, click **Use SSH**, then click ![The clipboard icon](icons/paste-24.svg). To clone a repository using GitHub CLI, click **Use GitHub CLI**, then click ![The clipboard icon](icons/paste-24.svg).
  ![The clipboard icon for copying the URL to clone a repository](./images/help/repository/https-url-clone.png)
4. Open Terminal.
3. Change directories to the location of the fork you cloned.
    - To go to your home directory, type just `cd` with no other text.
    - To list the files and folders in your current directory, type `ls`.
    - To go into one of your listed directories, type `cd your_listed_directory`.
    - To go up one directory, type `cd ..`.
4. Type `git remote -v` and press **Enter**. You'll see the current configured remote repository for your fork.
  ```shell
  $ git remote -v
  > origin  https://github.com/YOUR_USERNAME/YOUR_FORK.git (fetch)
  > origin  https://github.com/YOUR_USERNAME/YOUR_FORK.git (push)
  ```
6. Type `git remote add upstream`, and then paste the URL you copied in Step 2 and press **Enter**. It will look like this:
  ```shell
  $ git remote add upstream https://github.com/octocat/Spoon-Knife.git
  ```
7. To verify the new upstream repository you've specified for your fork, type `git remote -v` again. You should see the URL for your fork as `origin`, and the URL for the original repository as `upstream`.
  ```shell
  $ git remote -v
  > origin    https://github.com/YOUR_USERNAME/YOUR_FORK.git (fetch)
  > origin    https://github.com/YOUR_USERNAME/YOUR_FORK.git (push)
  > upstream  https://github.com/ORIGINAL_OWNER/ORIGINAL_REPOSITORY.git (fetch)
  > upstream  https://github.com/ORIGINAL_OWNER/ORIGINAL_REPOSITORY.git (push)
  ```

Now, you can keep your fork synced with the upstream repository with a few Git commands. For more information, see "[Syncing a fork](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/working-with-forks/syncing-a-fork)."
