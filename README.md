# 🚀 C언어 프로그래밍 실습 환경 (Codespaces)

이 저장소는 **GitHub Codespaces**를 활용하여 별도의 복잡한 설치 과정 없이 웹 브라우저에서 즉시 C언어 개발을 시작할 수 있도록 구성된 베이스 템플릿입니다.

## 1. 실습 준비하기 (최초 1회)

1. **저장소 복제**: 상단의 **[Use this template]** -> **[Create a new repository]** 버튼을 클릭하여 본인의 GitHub 계정으로 저장소를 생성합니다.
2. **Codespace 생성**: 생성된 본인의 저장소에서 **[<> Code]** 버튼 -> **[Codespaces]** 탭 -> **[Create codespace on main]**을 클릭합니다.
3. **환경 로딩**: 컨테이너 빌드가 완료될 때까지 약 1~2분 정도 기다립니다. VS Code 화면이 나타나면 모든 설정이 자동으로 완료됩니다.

## 2. 코드 작성 및 실행 방법

### 📝 파일 생성 및 편집

* **파일 생성**: 왼쪽 탐색기에서 새로운 `.c` 파일을 만들거나 기존 파일을 수정합니다.
* **자동 코드 정렬**: 코드를 작성하고 저장(`Ctrl + S`)하면 `clang-format` 설정에 따라 코드가 자동으로 예쁘게 정렬됩니다.

### ▶️ 코드 실행 (Code Runner)

오른쪽 상단의 **재생 버튼(▶)** 또는 `Ctrl+Alt+N`을 누르면 하단 터미널에서 즉시 컴파일 및 실행 결과가 나타납니다.

**컴파일 우선순위:**

1. **`makefile` 또는 `Makefile`이 있는 경우**
   * `make` 명령어를 자동으로 실행하여 프로젝트를 빌드합니다.
   * 여러 파일로 구성된 프로젝트에 적합합니다.
   * 예시: `sample_project/` 폴더 (여러 `.c` 파일과 헤더 파일로 구성)

2. **`makefile`이 없는 경우**
   * 단일 `.c` 파일을 `gcc`로 직접 컴파일합니다.
   * 출력 파일은 `.o` 확장자로 생성됩니다.
   * 예시: `sample/sample.c` 같은 단일 파일 프로젝트

**참고**: 빌드 산출물(`.o`, `.out` 등)은 `.gitignore`에 의해 자동으로 무시됩니다.

## 3. 주요 도구 활용법

### 🤖 GitHub Copilot & Chat

* **코드 추천**: 코드를 작성하면 Copilot이 회색 글씨로 다음 코드를 제안합니다. `Tab` 키를 눌러 수락하세요.
* **AI 채팅**: 왼쪽 사이드바의 **말풍선 아이콘(Chat)**을 클릭하여 문법 질문이나 에러 수정을 요청할 수 있습니다.

### 🌿 Git Flow (버전 관리)

수업 중 기능 단위 개발을 위해 Git Flow를 사용합니다. 터미널(Terminal)에서 아래 명령어를 사용하세요.

1. **초기화**: `git flow init -d` (최초 1회 실행)
2. **작업 시작**: `git flow feature start 실습이름`
3. **작업 완료**: `git flow feature finish 실습이름`

### 🔍 Error Lens & GitLens

* **Error Lens**: 컴파일 에러가 발생하면 터미널을 보기 전에도 코드 줄 옆에 빨간색으로 에러 내용이 즉시 표시됩니다.
* **GitLens**: 코드 라인별로 누가 언제 수정했는지 히스토리를 확인할 수 있습니다.

## ⚠️ 주의사항 (무료 사용량 관리)

GitHub Codespaces는 매달 무료 사용 시간이 정해져 있습니다. 사용하지 않을 때는 반드시 종료해야 합니다.

1. VS Code 왼쪽 하단의 **'Codespaces' (파란색 바)** 아이콘을 클릭합니다.
2. **[Stop Current Codespace]**를 선택하여 실행을 중지합니다.
   * *단순히 브라우저 탭만 닫으면 일정 시간 동안 컨테이너가 계속 작동하여 시간이 차감될 수 있습니다.*

## 🛠️ 포함된 개발 환경

* **OS**: Ubuntu Latest
* **Compiler**: GCC (build-essential)
* **Tools**: gdb, cmake, clang-format, git-flow
* **VS Code Extensions**: C/C++ Extension Pack, Code Runner, GitHub Copilot, GitLens, Git **Flow**
