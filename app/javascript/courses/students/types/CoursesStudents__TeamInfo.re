type student = {
  id: string,
  name: string,
  title: string,
  avatarUrl: option(string),
};

type t = {
  id: string,
  name: string,
  levelId: string,
  students: array(student),
  coachUserIds: array(string),
};

let id = t => t.id;
let levelId = t => t.levelId;

let name = t => t.name;

let title = t => t.title;

let students = t => t.students;

let coachUserIds = t => t.coachUserIds;

let studentId = (student: student) => student.id;

let studentName = (student: student) => student.name;

let studentTitle = (student: student) => student.title;

let studentAvatarUrl = student => student.avatarUrl;

let studentWithId = (studentId, t) =>
  t.students
  |> ArrayUtils.unsafeFind(
       (student: student) => student.id == studentId,
       "Could not find student with ID "
       ++ studentId
       ++ " in team with ID "
       ++ t.id,
     );

let makeStudent = (~id, ~name, ~title, ~avatarUrl) => {
  id,
  name,
  title,
  avatarUrl,
};

let make = (~id, ~name, ~levelId, ~students, ~coachUserIds) => {
  id,
  name,
  levelId,
  students,
  coachUserIds,
};

let makeFromJS = teamDetails => {
  let students =
    teamDetails##students
    |> Array.map(student =>
         makeStudent(
           ~id=student##id,
           ~name=student##name,
           ~title=student##title,
           ~avatarUrl=student##avatarUrl,
         )
       );

  make(
    ~id=teamDetails##id,
    ~name=teamDetails##name,
    ~levelId=teamDetails##levelId,
    ~students,
    ~coachUserIds=teamDetails##coachUserIds,
  );
};

let makeArrayFromJs = detailsOfTeams => {
  detailsOfTeams
  |> Js.Array.map(team =>
       switch (team) {
       | Some(team) => [makeFromJS(team)]
       | None => []
       }
     );
};

let otherStudents = (studentId, t) =>
  t.students |> Js.Array.filter((student: student) => student.id != studentId);
