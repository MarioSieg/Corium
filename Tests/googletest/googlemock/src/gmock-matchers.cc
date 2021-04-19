// File: gmock-matchers.cc
// Author: Mario
// Created: 16.04.2021 10:37
// Project: NominaxRuntime
// 
//                                  Apache License
//                            Version 2.0, January 2004
//                         http://www.apache.org/licenses/
// 
//    TERMS AND CONDITIONS FOR USE, REPRODUCTION, AND DISTRIBUTION
// 
//    1. Definitions.
// 
//       "License" shall mean the terms and conditions for use, reproduction,
//       and distribution as defined by Sections 1 through 9 of this document.
// 
//       "Licensor" shall mean the copyright owner or entity authorized by
//       the copyright owner that is granting the License.
// 
//       "Legal Entity" shall mean the union of the acting entity and all
//       other entities that control, are controlled by, or are under common
//       control with that entity. For the purposes of this definition,
//       "control" means (i) the power, direct or indirect, to cause the
//       direction or management of such entity, whether by contract or
//       otherwise, or (ii) ownership of fifty percent (50%) or more of the
//       outstanding shares, or (iii) beneficial ownership of such entity.
// 
//       "You" (or "Your") shall mean an individual or Legal Entity
//       exercising permissions granted by this License.
// 
//       "Source" form shall mean the preferred form for making modifications,
//       including but not limited to software source code, documentation
//       source, and configuration files.
// 
//       "Object" form shall mean any form resulting from mechanical
//       transformation or translation of a Source form, including but
//       not limited to compiled object code, generated documentation,
//       and conversions to other media types.
// 
//       "Work" shall mean the work of authorship, whether in Source or
//       Object form, made available under the License, as indicated by a
//       copyright notice that is included in or attached to the work
//       (an example is provided in the Appendix below).
// 
//       "Derivative Works" shall mean any work, whether in Source or Object
//       form, that is based on (or derived from) the Work and for which the
//       editorial revisions, annotations, elaborations, or other modifications
//       represent, as a whole, an original work of authorship. For the purposes
//       of this License, Derivative Works shall not include works that remain
//       separable from, or merely link (or bind by name) to the interfaces of,
//       the Work and Derivative Works thereof.
// 
//       "Contribution" shall mean any work of authorship, including
//       the original version of the Work and any modifications or additions
//       to that Work or Derivative Works thereof, that is intentionally
//       submitted to Licensor for inclusion in the Work by the copyright owner
//       or by an individual or Legal Entity authorized to submit on behalf of
//       the copyright owner. For the purposes of this definition, "submitted"
//       means any form of electronic, verbal, or written communication sent
//       to the Licensor or its representatives, including but not limited to
//       communication on electronic mailing lists, source code control systems,
//       and issue tracking systems that are managed by, or on behalf of, the
//       Licensor for the purpose of discussing and improving the Work, but
//       excluding communication that is conspicuously marked or otherwise
//       designated in writing by the copyright owner as "Not a Contribution."
// 
//       "Contributor" shall mean Licensor and any individual or Legal Entity
//       on behalf of whom a Contribution has been received by Licensor and
//       subsequently incorporated within the Work.
// 
//    2. Grant of Copyright License. Subject to the terms and conditions of
//       this License, each Contributor hereby grants to You a perpetual,
//       worldwide, non-exclusive, no-charge, royalty-free, irrevocable
//       copyright license to reproduce, prepare Derivative Works of,
//       publicly display, publicly perform, sublicense, and distribute the
//       Work and such Derivative Works in Source or Object form.
// 
//    3. Grant of Patent License. Subject to the terms and conditions of
//       this License, each Contributor hereby grants to You a perpetual,
//       worldwide, non-exclusive, no-charge, royalty-free, irrevocable
//       (except as stated in this section) patent license to make, have made,
//       use, offer to sell, sell, import, and otherwise transfer the Work,
//       where such license applies only to those patent claims licensable
//       by such Contributor that are necessarily infringed by their
//       Contribution(s) alone or by combination of their Contribution(s)
//       with the Work to which such Contribution(s) was submitted. If You
//       institute patent litigation against any entity (including a
//       cross-claim or counterclaim in a lawsuit) alleging that the Work
//       or a Contribution incorporated within the Work constitutes direct
//       or contributory patent infringement, then any patent licenses
//       granted to You under this License for that Work shall terminate
//       as of the date such litigation is filed.
// 
//    4. Redistribution. You may reproduce and distribute copies of the
//       Work or Derivative Works thereof in any medium, with or without
//       modifications, and in Source or Object form, provided that You
//       meet the following conditions:
// 
//       (a) You must give any other recipients of the Work or
//           Derivative Works a copy of this License; and
// 
//       (b) You must cause any modified files to carry prominent notices
//           stating that You changed the files; and
// 
//       (c) You must retain, in the Source form of any Derivative Works
//           that You distribute, all copyright, patent, trademark, and
//           attribution notices from the Source form of the Work,
//           excluding those notices that do not pertain to any part of
//           the Derivative Works; and
// 
//       (d) If the Work includes a "NOTICE" text file as part of its
//           distribution, then any Derivative Works that You distribute must
//           include a readable copy of the attribution notices contained
//           within such NOTICE file, excluding those notices that do not
//           pertain to any part of the Derivative Works, in at least one
//           of the following places: within a NOTICE text file distributed
//           as part of the Derivative Works; within the Source form or
//           documentation, if provided along with the Derivative Works; or,
//           within a display generated by the Derivative Works, if and
//           wherever such third-party notices normally appear. The contents
//           of the NOTICE file are for informational purposes only and
//           do not modify the License. You may add Your own attribution
//           notices within Derivative Works that You distribute, alongside
//           or as an addendum to the NOTICE text from the Work, provided
//           that such additional attribution notices cannot be construed
//           as modifying the License.
// 
//       You may add Your own copyright statement to Your modifications and
//       may provide additional or different license terms and conditions
//       for use, reproduction, or distribution of Your modifications, or
//       for any such Derivative Works as a whole, provided Your use,
//       reproduction, and distribution of the Work otherwise complies with
//       the conditions stated in this License.
// 
//    5. Submission of Contributions. Unless You explicitly state otherwise,
//       any Contribution intentionally submitted for inclusion in the Work
//       by You to the Licensor shall be under the terms and conditions of
//       this License, without any additional terms or conditions.
//       Notwithstanding the above, nothing herein shall supersede or modify
//       the terms of any separate license agreement you may have executed
//       with Licensor regarding such Contributions.
// 
//    6. Trademarks. This License does not grant permission to use the trade
//       names, trademarks, service marks, or product names of the Licensor,
//       except as required for reasonable and customary use in describing the
//       origin of the Work and reproducing the content of the NOTICE file.
// 
//    7. Disclaimer of Warranty. Unless required by applicable law or
//       agreed to in writing, Licensor provides the Work (and each
//       Contributor provides its Contributions) on an "AS IS" BASIS,
//       WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
//       implied, including, without limitation, any warranties or conditions
//       of TITLE, NON-INFRINGEMENT, MERCHANTABILITY, or FITNESS FOR A
//       PARTICULAR PURPOSE. You are solely responsible for determining the
//       appropriateness of using or redistributing the Work and assume any
//       risks associated with Your exercise of permissions under this License.
// 
//    8. Limitation of Liability. In no event and under no legal theory,
//       whether in tort (including negligence), contract, or otherwise,
//       unless required by applicable law (such as deliberate and grossly
//       negligent acts) or agreed to in writing, shall any Contributor be
//       liable to You for damages, including any direct, indirect, special,
//       incidental, or consequential damages of any character arising as a
//       result of this License or out of the use or inability to use the
//       Work (including but not limited to damages for loss of goodwill,
//       work stoppage, computer failure or malfunction, or any and all
//       other commercial damages or losses), even if such Contributor
//       has been advised of the possibility of such damages.
// 
//    9. Accepting Warranty or Additional Liability. While redistributing
//       the Work or Derivative Works thereof, You may choose to offer,
//       and charge a fee for, acceptance of support, warranty, indemnity,
//       or other liability obligations and/or rights consistent with this
//       License. However, in accepting such obligations, You may act only
//       on Your own behalf and on Your sole responsibility, not on behalf
//       of any other Contributor, and only if You agree to indemnify,
//       defend, and hold each Contributor harmless for any liability
//       incurred by, or claims asserted against, such Contributor by reason
//       of your accepting any such warranty or additional liability.
// 
//    END OF TERMS AND CONDITIONS
// 
//    APPENDIX: How to apply the Apache License to your work.
// 
//       To apply the Apache License to your work, attach the following
//       boilerplate notice, with the fields enclosed by brackets "[]"
//       replaced with your own identifying information. (Don't include
//       the brackets!)  The text should be enclosed in the appropriate
//       comment syntax for the file format. We also recommend that a
//       file or class name and description of purpose be included on the
//       same "printed page" as the copyright notice for easier
//       identification within third-party archives.
// 
//    Copyright 2021 Mario Sieg "pinsrq" <mt3000@gmx.de>
// 
//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at
// 
//        http://www.apache.org/licenses/LICENSE-2.0
// 
//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//    See the License for the specific language governing permissions and
//    limitations under the License.

#include "gmock/gmock-matchers.h"

#include <string.h>
#include <iostream>
#include <sstream>
#include <string>

namespace testing {
namespace internal {

// Returns the description for a matcher defined using the MATCHER*()
// macro where the user-supplied description string is "", if
// 'negation' is false; otherwise returns the description of the
// negation of the matcher.  'param_values' contains a list of strings
// that are the print-out of the matcher's parameters.
GTEST_API_ auto FormatMatcherDescription(bool negation,
                                         const char* matcher_name,
                                         const Strings& param_values) ->
std::string {
  std::string result = ConvertIdentifierNameToWords(matcher_name);
  if (param_values.size() >= 1) {
    result += " " + JoinAsTuple(param_values);
  }
  return negation ? "not (" + result + ")" : result;
}

// FindMaxBipartiteMatching and its helper class.
//
// Uses the well-known Ford-Fulkerson max flow method to find a maximum
// bipartite matching. Flow is considered to be from left to right.
// There is an implicit source node that is connected to all of the left
// nodes, and an implicit sink node that is connected to all of the
// right nodes. All edges have unit capacity.
//
// Neither the flow graph nor the residual flow graph are represented
// explicitly. Instead, they are implied by the information in 'graph' and
// a vector<int> called 'left_' whose elements are initialized to the
// value kUnused. This represents the initial state of the algorithm,
// where the flow graph is empty, and the residual flow graph has the
// following edges:
//   - An edge from source to each left_ node
//   - An edge from each right_ node to sink
//   - An edge from each left_ node to each right_ node, if the
//     corresponding edge exists in 'graph'.
//
// When the TryAugment() method adds a flow, it sets left_[l] = r for some
// nodes l and r. This induces the following changes:
//   - The edges (source, l), (l, r), and (r, sink) are added to the
//     flow graph.
//   - The same three edges are removed from the residual flow graph.
//   - The reverse edges (l, source), (r, l), and (sink, r) are added
//     to the residual flow graph, which is a directional graph
//     representing unused flow capacity.
//
// When the method augments a flow (moving left_[l] from some r1 to some
// other r2), this can be thought of as "undoing" the above steps with
// respect to r1 and "redoing" them with respect to r2.
//
// It bears repeating that the flow graph and residual flow graph are
// never represented explicitly, but can be derived by looking at the
// information in 'graph' and in left_.
//
// As an optimization, there is a second vector<int> called right_ which
// does not provide any new information. Instead, it enables more
// efficient queries about edges entering or leaving the right-side nodes
// of the flow or residual flow graphs. The following invariants are
// maintained:
//
// left[l] == kUnused or right[left[l]] == l
// right[r] == kUnused or left[right[r]] == r
//
// . [ source ]                                        .
// .   |||                                             .
// .   |||                                             .
// .   ||\--> left[0]=1  ---\    right[0]=-1 ----\     .
// .   ||                   |                    |     .
// .   |\---> left[1]=-1    \--> right[1]=0  ---\|     .
// .   |                                        ||     .
// .   \----> left[2]=2  ------> right[2]=2  --\||     .
// .                                           |||     .
// .         elements           matchers       vvv     .
// .                                         [ sink ]  .
//
// See Also:
//   [1] Cormen, et al (2001). "Section 26.2: The Ford-Fulkerson method".
//       "Introduction to Algorithms (Second ed.)", pp. 651-664.
//   [2] "Ford-Fulkerson algorithm", Wikipedia,
//       'http://en.wikipedia.org/wiki/Ford%E2%80%93Fulkerson_algorithm'
class MaxBipartiteMatchState {
public:
  explicit MaxBipartiteMatchState(const MatchMatrix& graph)
    : graph_(&graph),
      left_(graph_->LhsSize(), kUnused),
      right_(graph_->RhsSize(), kUnused) {}

  // Returns the edges of a maximal match, each in the form {left, right}.
  auto Compute() -> ElementMatcherPairs {
    // 'seen' is used for path finding { 0: unseen, 1: seen }.
    std::vector<char> seen;
    // Searches the residual flow graph for a path from each left node to
    // the sink in the residual flow graph, and if one is found, add flow
    // to the graph. It's okay to search through the left nodes once. The
    // edge from the implicit source node to each previously-visited left
    // node will have flow if that left node has any path to the sink
    // whatsoever. Subsequent augmentations can only add flow to the
    // network, and cannot take away that previous flow unit from the source.
    // Since the source-to-left edge can only carry one flow unit (or,
    // each element can be matched to only one matcher), there is no need
    // to visit the left nodes more than once looking for augmented paths.
    // The flow is known to be possible or impossible by looking at the
    // node once.
    for (size_t ilhs = 0; ilhs < graph_->LhsSize(); ++ilhs) {
      // Reset the path-marking vector and try to find a path from
      // source to sink starting at the left_[ilhs] node.
      GTEST_CHECK_(left_[ilhs] == kUnused)
          << "ilhs: " << ilhs << ", left_[ilhs]: " << left_[ilhs];
      // 'seen' initialized to 'graph_->RhsSize()' copies of 0.
      seen.assign(graph_->RhsSize(), 0);
      TryAugment(ilhs, &seen);
    }
    ElementMatcherPairs result;
    for (size_t ilhs = 0; ilhs < left_.size(); ++ilhs) {
      size_t irhs = left_[ilhs];
      if (irhs == kUnused) {
        continue;
      }
      result.push_back(ElementMatcherPair(ilhs, irhs));
    }
    return result;
  }

private:
  static const size_t kUnused = static_cast<size_t>(-1);

  // Perform a depth-first search from left node ilhs to the sink.  If a
  // path is found, flow is added to the network by linking the left and
  // right vector elements corresponding each segment of the path.
  // Returns true if a path to sink was found, which means that a unit of
  // flow was added to the network. The 'seen' vector elements correspond
  // to right nodes and are marked to eliminate cycles from the search.
  //
  // Left nodes will only be explored at most once because they
  // are accessible from at most one right node in the residual flow
  // graph.
  //
  // Note that left_[ilhs] is the only element of left_ that TryAugment will
  // potentially transition from kUnused to another value. Any other
  // left_ element holding kUnused before TryAugment will be holding it
  // when TryAugment returns.
  //
  auto TryAugment(size_t ilhs, std::vector<char>* seen) -> bool {
    for (size_t irhs = 0; irhs < graph_->RhsSize(); ++irhs) {
      if ((*seen)[irhs]) {
        continue;
      }
      if (!graph_->HasEdge(ilhs, irhs)) {
        continue;
      }
      // There's an available edge from ilhs to irhs.
      (*seen)[irhs] = 1;
      // Next a search is performed to determine whether
      // this edge is a dead end or leads to the sink.
      //
      // right_[irhs] == kUnused means that there is residual flow from
      // right node irhs to the sink, so we can use that to finish this
      // flow path and return success.
      //
      // Otherwise there is residual flow to some ilhs. We push flow
      // along that path and call ourselves recursively to see if this
      // ultimately leads to sink.
      if (right_[irhs] == kUnused || TryAugment(right_[irhs], seen)) {
        // Add flow from left_[ilhs] to right_[irhs].
        left_[ilhs] = irhs;
        right_[irhs] = ilhs;
        return true;
      }
    }
    return false;
  }

  const MatchMatrix* graph_; // not owned
  // Each element of the left_ vector represents a left hand side node
  // (i.e. an element) and each element of right_ is a right hand side
  // node (i.e. a matcher). The values in the left_ vector indicate
  // outflow from that node to a node on the right_ side. The values
  // in the right_ indicate inflow, and specify which left_ node is
  // feeding that right_ node, if any. For example, left_[3] == 1 means
  // there's a flow from element #3 to matcher #1. Such a flow would also
  // be redundantly represented in the right_ vector as right_[1] == 3.
  // Elements of left_ and right_ are either kUnused or mutually
  // referent. Mutually referent means that left_[right_[i]] = i and
  // right_[left_[i]] = i.
  std::vector<size_t> left_;
  std::vector<size_t> right_;
};

const size_t MaxBipartiteMatchState::kUnused;

GTEST_API_ auto FindMaxBipartiteMatching(
    const MatchMatrix& g) -> ElementMatcherPairs {
  return MaxBipartiteMatchState(g).Compute();
}

static auto LogElementMatcherPairVec(const ElementMatcherPairs& pairs,
                                     std::ostream* stream) -> void {
  using Iter = ElementMatcherPairs::const_iterator;
  std::ostream& os = *stream;
  os << "{";
  auto sep = "";
  for (Iter it = pairs.begin(); it != pairs.end(); ++it) {
    os << sep << "\n  ("
        << "element #" << it->first << ", "
        << "matcher #" << it->second << ")";
    sep = ",";
  }
  os << "\n}";
}

auto MatchMatrix::NextGraph() -> bool {
  for (size_t ilhs = 0; ilhs < LhsSize(); ++ilhs) {
    for (size_t irhs = 0; irhs < RhsSize(); ++irhs) {
      char& b = matched_[SpaceIndex(ilhs, irhs)];
      if (!b) {
        b = 1;
        return true;
      }
      b = 0;
    }
  }
  return false;
}

auto MatchMatrix::Randomize() -> void {
  for (size_t ilhs = 0; ilhs < LhsSize(); ++ilhs) {
    for (size_t irhs = 0; irhs < RhsSize(); ++irhs) {
      char& b = matched_[SpaceIndex(ilhs, irhs)];
      b = static_cast<char>(rand() & 1); // NOLINT
    }
  }
}

auto MatchMatrix::DebugString() const -> std::string {
  std::stringstream ss;
  auto sep = "";
  for (size_t i = 0; i < LhsSize(); ++i) {
    ss << sep;
    for (size_t j = 0; j < RhsSize(); ++j) {
      ss << HasEdge(i, j);
    }
    sep = ";";
  }
  return ss.str();
}

auto UnorderedElementsAreMatcherImplBase::DescribeToImpl(
    std::ostream* os) const -> void {
  switch (match_flags()) {
    case UnorderedMatcherRequire::ExactMatch:
      if (matcher_describers_.empty()) {
        *os << "is empty";
        return;
      }
      if (matcher_describers_.size() == 1) {
        *os << "has " << Elements(1) << " and that element ";
        matcher_describers_[0]->DescribeTo(os);
        return;
      }
      *os << "has " << Elements(matcher_describers_.size())
          << " and there exists some permutation of elements such that:\n";
      break;
    case UnorderedMatcherRequire::Superset:
      *os << "a surjection from elements to requirements exists such that:\n";
      break;
    case UnorderedMatcherRequire::Subset:
      *os << "an injection from elements to requirements exists such that:\n";
      break;
  }

  auto sep = "";
  for (size_t i = 0; i != matcher_describers_.size(); ++i) {
    *os << sep;
    if (match_flags() == UnorderedMatcherRequire::ExactMatch) {
      *os << " - element #" << i << " ";
    } else {
      *os << " - an element ";
    }
    matcher_describers_[i]->DescribeTo(os);
    if (match_flags() == UnorderedMatcherRequire::ExactMatch) {
      sep = ", and\n";
    } else {
      sep = "\n";
    }
  }
}

auto UnorderedElementsAreMatcherImplBase::DescribeNegationToImpl(
    std::ostream* os) const -> void {
  switch (match_flags()) {
    case UnorderedMatcherRequire::ExactMatch:
      if (matcher_describers_.empty()) {
        *os << "isn't empty";
        return;
      }
      if (matcher_describers_.size() == 1) {
        *os << "doesn't have " << Elements(1) << ", or has " << Elements(1)
            << " that ";
        matcher_describers_[0]->DescribeNegationTo(os);
        return;
      }
      *os << "doesn't have " << Elements(matcher_describers_.size())
          << ", or there exists no permutation of elements such that:\n";
      break;
    case UnorderedMatcherRequire::Superset:
      *os << "no surjection from elements to requirements exists such that:\n";
      break;
    case UnorderedMatcherRequire::Subset:
      *os << "no injection from elements to requirements exists such that:\n";
      break;
  }
  auto sep = "";
  for (size_t i = 0; i != matcher_describers_.size(); ++i) {
    *os << sep;
    if (match_flags() == UnorderedMatcherRequire::ExactMatch) {
      *os << " - element #" << i << " ";
    } else {
      *os << " - an element ";
    }
    matcher_describers_[i]->DescribeTo(os);
    if (match_flags() == UnorderedMatcherRequire::ExactMatch) {
      sep = ", and\n";
    } else {
      sep = "\n";
    }
  }
}

// Checks that all matchers match at least one element, and that all
// elements match at least one matcher. This enables faster matching
// and better error reporting.
// Returns false, writing an explanation to 'listener', if and only
// if the success criteria are not met.
auto UnorderedElementsAreMatcherImplBase::VerifyMatchMatrix(
    const std::vector<std::string>& element_printouts,
    const MatchMatrix& matrix, MatchResultListener* listener) const -> bool {
  bool result = true;
  std::vector<char> element_matched(matrix.LhsSize(), 0);
  std::vector<char> matcher_matched(matrix.RhsSize(), 0);

  for (size_t ilhs = 0; ilhs < matrix.LhsSize(); ilhs++) {
    for (size_t irhs = 0; irhs < matrix.RhsSize(); irhs++) {
      const char matched = matrix.HasEdge(ilhs, irhs);
      element_matched[ilhs] |= matched;
      matcher_matched[irhs] |= matched;
    }
  }

  if (match_flags() & UnorderedMatcherRequire::Superset) {
    auto sep =
        "where the following matchers don't match any elements:\n";
    for (size_t mi = 0; mi < matcher_matched.size(); ++mi) {
      if (matcher_matched[mi]) {
        continue;
      }
      result = false;
      if (listener->IsInterested()) {
        *listener << sep << "matcher #" << mi << ": ";
        matcher_describers_[mi]->DescribeTo(listener->stream());
        sep = ",\n";
      }
    }
  }

  if (match_flags() & UnorderedMatcherRequire::Subset) {
    auto sep =
        "where the following elements don't match any matchers:\n";
    auto outer_sep = "";
    if (!result) {
      outer_sep = "\nand ";
    }
    for (size_t ei = 0; ei < element_matched.size(); ++ei) {
      if (element_matched[ei]) {
        continue;
      }
      result = false;
      if (listener->IsInterested()) {
        *listener << outer_sep << sep << "element #" << ei << ": "
            << element_printouts[ei];
        sep = ",\n";
        outer_sep = "";
      }
    }
  }
  return result;
}

auto UnorderedElementsAreMatcherImplBase::FindPairing(
    const MatchMatrix& matrix, MatchResultListener* listener) const -> bool {
  ElementMatcherPairs matches = FindMaxBipartiteMatching(matrix);

  const size_t max_flow = matches.size();
  if (match_flags() & UnorderedMatcherRequire::Superset &&
      max_flow < matrix.RhsSize()) {
    if (listener->IsInterested()) {
      *listener << "where no permutation of the elements can satisfy all "
          "matchers, and the closest match is "
          << max_flow << " of " << matrix.RhsSize()
          << " matchers with the pairings:\n";
      LogElementMatcherPairVec(matches, listener->stream());
    }
    return false;
  }
  if (match_flags() & UnorderedMatcherRequire::Subset &&
      max_flow < matrix.LhsSize()) {
    if (listener->IsInterested()) {
      *listener
          << "where not all elements can be matched, and the closest match is "
          << max_flow << " of " << matrix.RhsSize()
          << " matchers with the pairings:\n";
      LogElementMatcherPairVec(matches, listener->stream());
    }
    return false;
  }

  if (matches.size() > 1) {
    if (listener->IsInterested()) {
      auto sep = "where:\n";
      for (size_t mi = 0; mi < matches.size(); ++mi) {
        *listener << sep << " - element #" << matches[mi].first
            << " is matched by matcher #" << matches[mi].second;
        sep = ",\n";
      }
    }
  }
  return true;
}

} // namespace internal
} // namespace testing
