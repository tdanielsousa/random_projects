# Reset Win10 Policies

A Windows batch script that fixes the **"Some settings are managed by your organization"** message in Windows 10 by resetting local group policies and removing policy registry keys.

> Disclaimer: This script deletes policy-related registry keys and group policy folders. It creates a restore point first, but use it at your own risk, and do not use it on a work or school managed machine.
---

##  How It Works

The script runs with administrator privileges and goes through a few steps to restore the default policy state.

### Phase 1: Preparation
* **Admin Check:** Uses `Net session` to detect admin rights and relaunches itself through PowerShell with `-RunAs` if needed.
* **Restore Point:** Runs `Checkpoint-Computer` to create a `LocalGroupPolicy` restore point before changing anything.

### Phase 2: Policy Reset
* **Security Database:** `secedit /configure` re-applies the default security template (`defltbase.inf`).
* **Group Policy Folders:** Removes `GroupPolicy` and `GroupPolicyUsers` from `System32`.
* **Registry Cleanup:** Deletes the `Policies` keys (and the `WindowsSelfHost` and `WindowsUpdate` policy keys) under `HKCU`, `HKLM` and `WOW6432Node`.

### Phase 3: Apply Changes
* **Policy Refresh:** `gpupdate /force` applies the reset right away.
* **Reboot Prompt:** Asks whether to reboot now (`Y`) or exit the script (`N`).

---

## Installation & Run Steps

### 1. Download the Script
Save the script as a `.bat` file, for example `reset_policies.bat`.

### 2. Run It
Double-click the file, or run it from a terminal:

    reset_policies.bat

If it is not running as administrator, it asks for elevation by itself (accept the UAC prompt).

### 3. Reboot
Press `Y` when prompted to restart so the changes take full effect.

---

## Requirements

* Windows 10
* Administrator rights
* PowerShell (included with Windows)
* System Restore enabled, if you want the restore point to be created

---

## AI Usage Declaration

AI tools were used to assist with:

* **Documentation Support:** Structuring and writing this README file.

---