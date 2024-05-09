class User {
  constructor(name, email) {
    this._name = name;
    this._email = email;
  }

  get name() {
    return this._name;
  }
  set name(newName) {
    this._name = newName;
  }
  get email() {
    return this._email;
  }
  set email(newEmail) {
    this._email = newEmail;
  }
}

class Administrator extends User {
  constructor(name, email) {
    super(name, email);
    this._role = "administrator";
  }
  get role() {
    return this._role;
  }
  set role(value) {
    throw new Error("The admnistrator role can not be changed");
  }
}

const exampleUser = new User("nome", "email@email.com");
const exampleAdm = new Administrator("admin", "admin@admin.com");
exampleUser.name = "newUserName";
exampleAdm.name = "newAdminName";
// exampleAdm.role = "newAdminRole" // throws error!
